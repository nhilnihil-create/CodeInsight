#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 2000000001;
constexpr ll INF= 9 * 1e18;
constexpr ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<int,int> P;

ll RepeatSquaring(ll N, ll P, ll M){
    if(P < 0) {
        return 0;
    }
    if(P==0) return 1;
    if(P%2==0){
        ll t = RepeatSquaring(N, P/2, M);
        return t*t % M;
    }
    return N * RepeatSquaring(N, P-1, M);
}

int main() {
    string S;
    cin >> S;
    int N = S.size();
    vector<ll> q(N + 1);
    for(int i = 0;i < N;i++) {
        if(S.at(i) == '?') {
            q.at(i + 1) = q.at(i) + 1;
        }
        else {
            q.at(i + 1) = q.at(i);
        }
    }
    vector<ll> A(N + 1);
    for(int i = 0;i < N;i++) {
        if(S.at(i) == 'A') {
            A.at(i + 1) = A.at(i) + 1;
        }
        else {
            A.at(i + 1) = A.at(i);
        }
    }
    vector<ll> C(N + 1);
    for(int i = N;i >= 1;i--) {
        if(S.at(i - 1) == 'C') {
            C.at(i - 1) = C.at(i) + 1;
        }
        else {
            C.at(i - 1) = C.at(i);
        }
    }
    ll ret = 0;
    for(int i = 0;i < N;i++) {
        if(S.at(i) == 'B' || S.at(i) == '?') {
            ll cnt = 0;
            cnt += A.at(i) * RepeatSquaring(3ll,q.at(i),MOD);
            cnt %= MOD;
            cnt += q.at(i) * RepeatSquaring(3ll,q.at(i) - 1,MOD);
            cnt %= MOD;
            ll cnt2 = 0;
            cnt2 += C.at(i + 1) * RepeatSquaring(3ll,q.at(N) - q.at(i + 1),MOD);
            cnt2 %= MOD;
            cnt2 += (q.at(N) - q.at(i + 1)) * RepeatSquaring(3ll,q.at(N) - q.at(i + 1) - 1,MOD);
            cnt2 %= MOD;
            ret += cnt * cnt2;
            ret %= MOD;
        }
    }
    cout << ret << endl;
}