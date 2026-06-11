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
    
    int a,b;
    cin>>a>>b;
    cout<<100<<" "<<100<<endl;
    char c[100][100];
    rep(i,100) c[i][0]='#';
    rep(i,100) c[i][99]='.';
    rep(i,100){
        for(int j=1;j<99;j++){
            if(i%2==0) c[i][j]='#';
            else c[i][j]='.';
        }
    }

    a--;b--;
    // aが白　bが黒
    for(int i=1;i<50;i+=2){
        for(int j=2;j<90;j+=2){
            if(a>0){
                c[i][j]='#';
                a--;
            }
        }
    }

    for(int i=98;i>50;i-=2){
        for(int j=97;j>=5;j-=2){
            if(b>0){
                c[i][j]='.';
                b--;
            }
        }
    }

    rep(i,100){
        rep(j,100){
            cout<<c[i][j];
        }
        cout<<endl;
    }
    
}