#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vc = vector<char>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using stkll = vector<pll>;
const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;
#define rep(i, n) for (ll i = 0; i < (n); i++)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
#ifndef ONLINE_JUDGE
    #define debug(x) cerr << #x << ": " << x << endl;
#else
    #define debug(x)
#endif

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll N; cin >> N;
    vll p(N), a(N);
    rep(i, N) {
        cin >> p[i];
        p[i]--;
        a[p[i]] = i;
    }

    ll cnt = 1, tmp = 1;
    for(ll i = 1; i < N; i++) {
        if(a[i-1] < a[i]) tmp++;
        if(a[i-1] >= a[i] || i == N-1) {
            chmax(cnt, tmp);
            tmp = 1;
        }
    }
    cout << N - cnt << endl;
}
