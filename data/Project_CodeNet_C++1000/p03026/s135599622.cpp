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
ll M = 1000000007;

int main(){
    ll N; cin >> N;
    vvll e(N+1, vll(0));
    vector<P> h(0);
    rep(i, 0, N-1){
        ll a, b; cin >> a >> b;
        e[a].emplace_back(b);
        e[b].emplace_back(a);
        h.emplace_back(P(max(a,b), min(a,b)));
    }
    vll c(N);
    ll s = 0;
    rep(i, 0, N){
        cin >> c[i];
        s += c[i];
    }
    sort(c.begin(),c.end(),greater<ll>());
    vll num(N+1);
    num[1] = c[0];
    queue<ll> q;
    for(auto x:e[1]){
        q.push(x);
    }
    vb ald(N+1, false);
    ald[1] = true;
    ll t = 1;
    while(!q.empty()){
        ll a = q.front();
        ald[a] = true;
        num[a] = c[t];
        q.pop();
        for(auto x: e[a]){
            if(!ald[x]){
                q.push(x);
            }
        }
        t++;
    }
    prtl(s-c[0]);
    rep(i, 1, N+1){
        prt(num[i]); prt(" ");
    }
}