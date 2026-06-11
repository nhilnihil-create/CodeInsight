#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define endl "\n"
#define sz(x) ((ll)(x).size())
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define prt(x) cout << (x)
#define prtl(x) cout << (x) << endl
#define rep(i,a,b) for(ll i=a; i<b; i++)
#define rrep(i,a,b) for(ll i=a; i>b; i--)
#define mp(a, b) make_pair(a, b)
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define debug(v) cout << #v<< ": " << v <<endl;
#define fst first
#define snd second
using namespace std;
using vi = vector<int>;
using vll = vector<long long int>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
using vc = vector<char>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<long long int>>;
using vvc = vector<vector<char>>;
using ll = long long int;
using P = pair<long long int, long long int>;
using Map = map<long long int, long long int>;
ll INF = 1LL<<60;
ll M = 1000003;

void dfs(ll a, ll c, const vector<vector<P>> &e, vll &ans){
    for(auto x: e[a]){
        ll s = x.fst, t = x.snd;
        if(ans[s] < INF){
            continue;
        }
        if(t%2 == 0){
            ans[s] = c;
        }else{
            if(c){
                ans[s] = 0;
            }else{
                ans[s] = 1;
            }
        }
        dfs(s, ans[s], e, ans);
    }
}

int main(){
    ll n; cin >> n;
    vector<vector<P>> e(n+1, vector<P>(0));
    rep(i, 1, n){
        ll a, b, c; cin >> a >> b >> c;
        e[a].emplace_back(mp(b,c));
        e[b].emplace_back(mp(a,c));
    }
    vll ans(n+1, INF);
    ans[1] = 1;
    dfs(1, 1, e, ans);
    rep(i, 1, n+1){
        prtl(ans[i]);
    }
}
