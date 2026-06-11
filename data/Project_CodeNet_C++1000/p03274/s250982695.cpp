#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
const ll INF = 1LL<<60;
const ll MOD = 1e9 + 7;


ll solve(ll N,ll K,vector<ll> P,vector<ll> M) {
    ll ans = INF;
    if (P.size() == 0) return -M.at(K-1);
    if (M.size() == 0) return P.at(K-1);
    for (ll i = 0;i<P.size();i++) { //プラスでi+1個つける
        //cout << i << endl;
        ll p = P.at(i); //pで折り返す
        if (K - (i+1) - 1 < 0) break;
        if (M.size() >= K - (i+1)) {
            //cout << K - (i+1) << endl;
            ll m;
            m = M.at(K-(i+1)-1); //マイナスでK - (i+1)個つける
            ans = min(ans,p*2+(-m)); //プラスで引き返す
            ans = min(ans,p+(-m*2)); //マイナスで引き返す
        }
        else continue;
    }
    return ans;
}

int main() {
    ll N,K;
    cin >> N >> K;
    vector<ll> P;
    vector<ll> M;
    for (ll i = 0;i<N;i++) {
        ll a;
        cin >> a;
        if (a >= 0) P.push_back(a);
        else M.push_back(a);
    }
    sort(M.begin(),M.end());
    reverse(M.begin(),M.end());
    ll res; 
    res = solve(N,K,P,M);
    cout << res << endl;
}