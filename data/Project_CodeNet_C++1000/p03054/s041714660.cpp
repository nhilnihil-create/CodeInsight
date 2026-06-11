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
// const int INF = (1 << 30); // 1073741824
const int INF = (1LL << 60); // 1152921504606846976
const double EPS = (1 >> 30);
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return 1;} return 0;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return 1;} return 0;}
template< typename T1, typename T2 > istream &operator>>(istream &is, pair< T1, T2 > &p) { is >> p.first >> p.second; return is; }



signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15);
    //---------------------------------------------
    
    int h,w,n;
    cin>>h>>w>>n;
    int x,y;
    cin>>x>>y;
    x--,y--;
    string s,t;
    cin>>s>>t;
    int ans=0;
    int memo;
    memo=y;
    rep(i,n){// Rに落とす
        if(s[i]=='R') memo++;
        if(memo>=w) ans++;
        if(t[i]=='L') memo--;
        chmax(memo,0LL);
    }
    // debug(ans);
    memo=y;
    rep(i,n){// Lに落とす
        if(s[i]=='L') memo--;
        if(memo<0) ans++;
        if(t[i]=='R') memo++;
        chmin(memo,w-1);
    }
    // debug(ans);
    memo=x;
    rep(i,n){// Dに落とす
        if(s[i]=='D') memo++;
        if(memo>=h) ans++;
        if(t[i]=='U') memo--;
        chmax(memo,0LL);
    }
    // debug(ans);
    memo=x;
    rep(i,n){// Dに落とす
        if(s[i]=='U') memo--;
        if(memo<0) ans++;
        if(t[i]=='D') memo++;
        chmin(memo,h-1);
    }
    // debug(ans);
    if(ans!=0){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
    }
}