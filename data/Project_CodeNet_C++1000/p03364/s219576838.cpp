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
    vvc S(N, vc(N));
    vc lis(0);
    rep(i, 0, N){
        rep(j, 0, N){
            cin >> S[i][j];
        }
    }
    map<char, vector<P>> m;
    rep(i, 0, N){
        rep(j, 0, N){
            if(m.find(S[i][j]) == m.end()){
                lis.emplace_back(S[i][j]);
                vector<P> h(0);
                h.emplace_back(P(i, j));
                m[S[i][j]] = h;
            }else{
                m[S[i][j]].emplace_back(P(i,j));
            }
        }
    }
    vector<P> q;
    rep(i, 0, N){
        q.emplace_back(P(i,0));
    }
    rep(i, 1, N){
        q.emplace_back(P(0,i));
    }
    for(auto x: lis){
        vector<P> t = m[x];
        ll m = sz(q);
        vector<P> r(0);
        rep(j, 0, m){
            P s = q[j];
            ll a = s.first, b = s.second;
            bool isok = true;
            for(auto y: t){
                bool ok = false;
                ll c = y.first, d = y.second;
                ll e = d - b + a, f = c - a + b;
                if(e<0){e = N + e;}
                else if(e > N-1){e = e%N;}
                if(f<0){f = N + f;}
                else if(f > N-1){f = f%N;}
                if(c == d){ok = true;}
                else{
                    if(S[c][d] == S[e][f]){ok = true;}
                }
                if(!ok){isok = false;}
            }
            if(isok){r.emplace_back(s);}
        }
        q = r;
    }
    ll ans = 0;
    for(auto x:q){
        ll n = max(x.first, x.second);
        ans += N - n;
    }
    prt(ans);
}