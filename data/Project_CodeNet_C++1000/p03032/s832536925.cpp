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
    ll N, K; cin >> N >> K;
    vll v(N);
    vll cum(N);
    ll sum = 0;
    rep(i, 0, N){
        cin >> v[i];
        sum += v[i];
        cum[i] = sum;
    }
    ll ans = 0;
    rep(i, 0, K+1){
        ll r = K - i;
        rep(j, 0, r+1){
            if(i + j > N){
                break;
            }
            vll g(0);
            ll ms = 0;
            rep(k, 0, i){
                g.emplace_back(v[k]);
                ms += v[k];
            }
            rrep(k, N-1, N-1-j){
                g.emplace_back(v[k]);
                ms += v[k];
            }
            ll l = K - (i + j);
            //prtl(ms);
            sort(g.begin(),g.end());
            ll t = sz(g);
            rep(i, 0, l){
                if(i >= t){
                    break;
                }
                else if(g[i]<0){
                    ms -= g[i];
                }else{
                    break;
                }
            }
            ans = max(ans, ms);
        }
    }
    prt(ans);
}