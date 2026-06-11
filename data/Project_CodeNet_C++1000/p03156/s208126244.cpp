#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 1000000000;
constexpr ll INF= 1e18;
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

int main() {
    int N,A,B;
    cin >> N >> A >> B;
    int cnt1 = 0;
    int cnt2 = 0;
    int cnt3 = 0;
    for(int i = 0;i < N;i++) {
        int C;
        cin >> C;
        if(C <= A) {
            cnt1++;
        }
        else if(C <= B) {
            cnt2++;
        }
        else {
            cnt3++;
        }
    }
    cout << min(cnt1,min(cnt2,cnt3)) << endl;
}