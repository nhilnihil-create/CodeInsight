#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vc = vector<char>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define rrep(i, n, k) for (ll i = n; i >= k; i--)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
#ifndef ONLINE_JUDGE
    #define debug(x) cerr << #x << ": " << x << endl;
#else
    #define debug(x)
#endif

int main() {
    cin.tie(0);ios::sync_with_stdio(false);cout << fixed << setprecision(20);

    ll M, K;
    cin >> M >> K;

    if(M == 0) {
        if(K == 0) cout << "0 0" << endl;
        else cout << -1 << endl;
        return 0;
    }
    if(M == 1) {
        if(K == 0) cout << "0 0 1 1" << endl;
        else cout << -1 << endl;
        return 0;
    }
    if(M >= 2) {
        if(K <= pow(2, M) - 1) {
            rep(i, pow(2, M)) {
                if(i == K) continue;
                cout << i << " ";
            }
            cout << K << " ";
            rrep(i, pow(2, M)-1, 0) {
                if(i == K) continue;
                cout << i << " ";
            }
            cout << K << endl;
        }
        else cout << -1 << endl;
    }
}
