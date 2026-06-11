// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i, n) for (int i = 0; i < n; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)
#define range(i,a,b) ((a)<=(i) && (i)<(b))
#define debug(x) cout << #x << ' ' << '=' << ' ' << (x) << endl;
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
typedef vector<ll> vec;
typedef vector<P> pvec;
typedef vector<vector<ll>> vvec;
typedef vector<vector<P>> pvvec;
typedef priority_queue<ll> PQI;
typedef priority_queue<P> PQP;
typedef priority_queue<ll,vector<ll>,greater<ll>> PQIG;
typedef priority_queue<P,vector<P>,greater<P>> PQPG;
const vector<int> dx = {0, -1, 0, 1, 1, 1, -1, -1};
const vector<int> dy = {1, 0, -1, 0, 1, -1, 1, -1};
const int MOD = (1000000007);
// const int MOD = (998244353);
// const int INF = (1 << 30);
const int INF = (1LL << 60);
const double EPS = (1 >> 30);
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return 1;} return 0;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return 1;} return 0;}
template< typename T1, typename T2 > istream &operator>>(istream &is, pair< T1, T2 > &p) { is >> p.first >> p.second; return is; }
template< typename T > istream &operator>>(istream &is, vector< T > &v) { for(T &in : v) is >> in; return is; }



signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15);
    //---------------------------------------------
    
    int n,c;
    cin>>n>>c;
    int d[c][c];
    rep(i,c){
        rep(j,c){
            cin>>d[i][j];
        }
    }
    int cc[n][n];
    vec a0(c);
    vec a1(c);
    vec a2(c);
    rep(i,n){
        rep(j,n){
            cin>>cc[i][j];
            cc[i][j]--;
            if((i+j)%3==0) a0[cc[i][j]]++;
            if((i+j)%3==1) a1[cc[i][j]]++;
            if((i+j)%3==2) a2[cc[i][j]]++;
        }
    }
    ll ans=INF;
    rep(i,c){
        rep(j,c){
            if(i==j) continue;
            rep(k,c){
                if(j==k||i==k) continue;
                int memo=0;
                rep(l,c){ // lは色
                    memo+=d[l][i]*a0[l];
                    memo+=d[l][j]*a1[l];
                    memo+=d[l][k]*a2[l];
                }
                chmin(ans,memo);
            }
        }
    }
    cout<<ans<<endl;
    
}