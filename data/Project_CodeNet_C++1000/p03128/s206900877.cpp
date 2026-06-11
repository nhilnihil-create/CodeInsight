#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<vector<vector<ll>>> vvvl;
struct edge{ll to,cost;};
const int inf = 1<<28;
const ll INF = 1LL<<53;
const int COMBMAX = 500005;
const ll MOD = 1e9+7;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<n;++i)
#define repf(i,n) for(int i=0;i<=n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define eachdo(v, e) for(const auto& e : v)
#define all(v) (v).begin(), (v).end()
#define lower_index(v, e) (ll)distance(v.begin(), lower_bound((v).begin(), (v).end(), e))
#define upper_index(v, e) (ll)distance(v.begin(), upper_bound((v).begin(), (v).end(), e))
ll mpow(ll a, ll n,ll mod=MOD){ll res=1;while(n>0){if(n&1)res=res*a%mod;a=a*a%mod;n>>=1;}return res;}
template<class T1, class T2> ll bcount(T1 v, T2 a){return upper_index(v,a)-lower_index(v,a);} 
template<class T> bool chmin(T &a, T b){if(a>b){a=b;return true;}return false;}
template<class T> bool chmax(T &a, T b){if(a<b){a=b;return true;}return false;}
template<class T> void debug(T v){rep(i,v.size()) cout<<v[i]<<" ";cout<<endl;}
template<class T> void debug2(T v){rep(i,v.size()){rep(j,v[i].size())cout<<v[i][j]<<" ";cout<<endl<<endl;}}
template<class T> void rdv(T &v){rep(i,v.size())cin>>v[i];}
template<class T> void rdvv(T &v){rep(i,v.size()){rep(j,v[i].size())cin>>v[i][j];}}
// multimap
// mmap.emplace(key,value);
// auto ngw = list.equal_range("");
// for(auto e = ngw.first; it != ngw.second ; ++e)

int N, M;
vector<bool> canUse(9);
vector<int> w = {2, 5, 5, 4, 5, 6, 3, 7, 6};
vector<int> r = {0, 6, 3, 4, 2, 1, 8, 5, 7};
bool compVector(vector<int> &a, vector<int> &b){
    int me = 0, aw = 0;
    rep(i, 9){
        me += a[i];
        aw += b[i];
    }
    if (me > aw){
        return true;
    }else if (me < aw){
        return false;
    }else
    {
        for(int i = 8; 0 <= i; i--){
            if (a[i] > b[i]){
                return true;
            }else if (a[i] < b[i]){
                return false;
            }
        }
    }
    return true;
}

// void vectorAdd(vector<int> &a, vector<int> &b){
//     return;
// }

void puts(vector<int> &vc){
    rep(i, 9){
        rep(j, vc[8 - i]){
            cout << (9 - i);
        }
    }
    cout << endl;
    return;
}


int main(){
    cin >> N >> M;
    rep(i, M){
        int a; cin >> a;
        canUse[a - 1] = true;
    }

    vector<vector<vector<int>>> dp(10, vector<vector<int>>(N + 1 , vector<int>(9, -99999999)));
    rep(i, 9) dp[0][0][i] = 0;
    rep(i, 9){
        rep(j, N + 1){
            rep(k, 9) dp[i + 1][j][k] = dp[i][j][k];
            if(canUse[r[i]] && 0 <= j - w[r[i]]){
                vector<int> fcomp(9, 0);
                rep(k, 9) fcomp[k] = dp[i + 1][j - w[r[i]]][k];
                fcomp[r[i]]++;
                // debug(fcomp);
                if(!compVector(dp[i + 1][j], fcomp)){
                    rep(k, 9) dp[i + 1][j][k] = dp[i + 1][j - w[r[i]]][k];
                    dp[i + 1][j][r[i]] += 1;
                }
            }
        }
    }
    //debug2(dp[9]);
    puts(dp[9][N]);
    return 0;
}