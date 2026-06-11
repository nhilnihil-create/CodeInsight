#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) (x = max(x,y))
#define mins(x,y) (x = min(x,y))
#define limit(x,l,r) max(l,min(x,r))
#define lims(x,l,r) (x = max(l,min(x,r)))
#define isin(x,l,r) ((l) <= (x) && (x) < (r))
#define pb push_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcountll
#define uni(x) x.erase(unique(rng(x)),x.end())
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
#define show(x) cout<<#x<<" = "<<x<<endl;
#define PQ(T) priority_queue<T,v(T),greater<T> >
#define bn(x) ((1<<x)-1)
#define dup(x,y) (((x)+(y)-1)/(y))
#define newline puts("")
#define v(T) vector<T>
#define vv(T) v(v(T))
using namespace std;
typedef long long int ll;
typedef unsigned uint;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
inline int in() { int x; scanf("%d",&x); return x;}
template<typename T>inline istream& operator>>(istream&i,v(T)&v)
{rep(j,sz(v))i>>v[j];return i;}
template<typename T>string join(const v(T)&v)
{stringstream s;rep(i,sz(v))s<<' '<<v[i];return s.str().substr(1);}
template<typename T>inline ostream& operator<<(ostream&o,const v(T)&v)
{if(sz(v))o<<join(v);return o;}
template<typename T1,typename T2>inline istream& operator>>(istream&i,pair<T1,T2>&v)
{return i>>v.fi>>v.se;}
template<typename T1,typename T2>inline ostream& operator<<(ostream&o,const pair<T1,T2>&v)
{return o<<v.fi<<","<<v.se;}
template<typename T>inline ll suma(const v(T)& a) { ll res(0); for (auto&& x : a) res += x; return res;}
const double eps = 1e-10;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define dame { puts("-1"); return 0;}
#define yn {puts("YES");}else{puts("NO");}
const int MX = 200005;

    // 整数スキャン（複数）
    /*
    int x;
    scanf("%d",&x);
    int y;
    scanf("%d",&y);
    int z;
    scanf("%d",&y);

    // n個の整数のスキャン
    /*
    ll a[n] = {};
    rep(i,n){
        scanf("%lld",&a[i]);
    }
    */

    // 文字列スキャン
    /*
    string s;
    cin >> s;
    */


int main() {
    int n;
    scanf("%d",&n);
    ll c;
    scanf("%lld",&c);
    ll x[n] = {};
    ll v[n] = {};

    rep(i,n){
        scanf("%lld",&x[i]);
        scanf("%lld",&v[i]);
    }

    ll now1 = 0;
    ll point1 = 0;
    ll max = 0;
    ll max1[n] = {};
    //cout << "tokei" << endl;
    rep(i,n){
        point1 = point1 - (x[i]-now1) + v[i];
        now1 = x[i];
        if(max<point1){
            max = point1;
        }
        max1[i] = max;
        //cout << max << endl;
    }

    ll now2 = c;
    ll point2 = 0;
    max = 0;
    ll max2[n] = {};
    //cout << "hantokei" << endl;
    drep(i,n){
        point2 = point2 - (now2-x[i]) + v[i];
        now2 = x[i];
        if(max<point2){
            max = point2;
        }
        max2[i] = max;
        //cout << max << endl;
    }

    ll ans = 0;
    if(max1[n-1]>ans){
        ans = max1[n-1];
    }
    if(max2[0]>ans){
        ans = max2[0];
    }

    //cout << "tokeiandgyaku" << endl;
    rep(i,n-1){
        if(ans<max1[i] - x[i] + max2[i+1]){
            ans = max1[i] - x[i] + max2[i+1];
        }
        //cout << ans << endl;
    }

    //cout << "hantokeiandgyaku" << endl;
    for(int i=n-1;i>=1;i--){
        if(ans<max2[i] - c + x[i] + max1[i-1]){
            ans = max2[i] - c + x[i] + max1[i-1];
        }
        //cout << ans << endl;
    }

    //cout << "kekka" << endl;
    cout << ans << endl;
    return 0;
}
 
 
