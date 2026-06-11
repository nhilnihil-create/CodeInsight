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
vvll lis(0, vll(3));

void dfs(ll a, vll p, ll C){
    if(a == 3){
        lis.emplace_back(p);
        return;
    }
    rep(i, 1, C+1){
        vll f = p;
        f.emplace_back(i);
        dfs(a+1, f, C);
    }
}

int main(){
    ll N, C; cin >> N >> C;
    ll D[C+1][C+1];
    rep(i, 1, C+1){
        rep(j, 1, C+1){
            cin >> D[i][j];
        }
    }
    ll c[N+1][N+1];
    rep(i, 1, N+1){
        rep(j, 1, N+1){
            cin >> c[i][j];
        }
    }
    vector<P> c0(0), c1(0), c2(0);
    vll C0(C+1, 0), C1(C+1, 0), C2(C+1, 0);
    rep(i, 1, N+1){
        rep(j, 1, N+1){
            if((i+j)%3==0){
                C0[c[i][j]]++;
            }else if((i+j)%3==1){
                C1[c[i][j]]++;
            }else{
                C2[c[i][j]]++;
            }
        }
    }
    rep(i, 1, C+1){
        if(C0[i] > 0){
            c0.emplace_back(mp(i, C0[i]));
        }
        if(C1[i] > 0){
            c1.emplace_back(mp(i, C1[i]));
        }
        if(C2[i] > 0){
            c2.emplace_back(mp(i, C2[i]));
        }
    }
    vll t(0);
    dfs(0, t, C);
    ll ans = 10000000000000;
    for(auto x: lis){
        if(x[0]==x[1]||x[0]==x[2]||x[1]==x[2]){
            continue;
        }else{
            ll m = 0;
            for(auto y: c0){
                ll s = y.first, t = y.second;
                if(x[0] != s){
                    m += t*D[s][x[0]];
                }
            }
            for(auto y: c1){
                ll s = y.first, t = y.second;
                if(x[1] != s){
                    m += t*D[s][x[1]];
                }
            }
            for(auto y: c2){
                ll s = y.first, t = y.second;
                if(x[2] != s){
                    m += t*D[s][x[2]];
                }
            }
            ans = min(m, ans);
        }
    }
    prt(ans);
}