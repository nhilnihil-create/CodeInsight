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


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15);
    //---------------------------------------------
    
    int n;
    cin>>n;
    ll a[n+10];
    REP(i,n) cin >> a[i+1];
    a[0]=0;
    rep(i,n){
        a[i+1]+=a[i];
    }
    ll ans=INF;
    for(int i=2;i<n-1;i++){ // iは２番目の仕切り
        int *p1,*p2,s;
        p1=lower_bound(a+1,a+i+1,a[i]/2+1); // 1~iに分けられた時の1番目の仕切りをa[i]/2に近いところを選ぶ
        p2=lower_bound(a+i+1,a+n+1,(a[n]+a[i])/2+1); // i~n
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                s=max({*p1,a[i]-*p1,*p2-a[i],a[n]-*p2})-min({*p1,a[i]-*p1,*p2-a[i],a[n]-*p2}); // j,kでp1.p2の周辺を探る・・賢い
                ans=min(ans,s);
                p1--;
            }
            p1+=2;
            p2--;
        }
    }

    cout<<ans<<endl;


    
}
