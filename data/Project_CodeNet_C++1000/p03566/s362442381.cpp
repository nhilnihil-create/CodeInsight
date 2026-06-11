#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 1000000010;
constexpr ll INF= 1000000000000000000;
constexpr ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<ll,ll> P;

template<typename T>
T Pow(T a,T b) {
    T ret = 1;
    for(int i = 0;i < b;i++) {
        ret *= a;
    }
    return ret;
}
 
ll mod(ll val) {
    ll res = val % MOD;
    if(res < 0) {
        res += MOD;
    }
    return res;
}
 
ll RS(ll N, ll P, ll M){
    if(P==0) return 1;
    if(P < 0) {
        return 0;
    }
    if(P%2==0){
        ll t = RS(N, P/2, M);
        return t*t % M;
    }
    return N * RS(N, P-1, M) % M;
}

int main() {
    int N;
    cin >> N;
    vector<int> t(N + 1);
    for (int i = 1; i <= N; ++i)
    {
        int A;
        cin >> A;
        t.at(i) = t.at(i - 1) + A * 2;
    }
    int time = t.at(N);
    vector<double> v(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> v.at(i);
    }
    vector<double> Max(time + 1);
    for (int i = 0; i <= time; ++i)
    {
        if(time / 2 >= i) {
            Max.at(i) = i * 0.5;
        }
        else {
            Max.at(i) = time / 2 * 0.5 - (i - time / 2) * 0.5;
        }
    }
    for (int i = 0; i <= time; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if(i <= t.at(j)) {
                Max.at(i) = min(Max.at(i),v.at(j) + (t.at(j) - i) * 0.5);
            }
            else if(t.at(j) < i && i < t.at(j + 1)) {
                Max.at(i) = min(Max.at(i),v.at(j));
            }
            else {
                Max.at(i) = min(Max.at(i),v.at(j) + (i - t.at(j + 1)) * 0.5);
            }
        }
    }
    double ret = 0;
    for (int i = 0; i < time; ++i)
    {
        ret += (Max.at(i) + Max.at(i + 1)) / 4.0;
    }
    cout << fixed;
    cout << setprecision(10) << ret << endl;
}