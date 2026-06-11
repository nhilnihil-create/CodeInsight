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
#define yn {puts("Yes");}else{puts("No");}
const int MX = 200005;
#define RET(ans) {cout<<ans<<endl;return 0;} 

    // 二次元ベクターの基本
    /*
    vector<vector<int>> dp; // 宣言
    dp.resize(n); // 1次元めの要素数決定
    dp[i].push_back(int); // プッシュバック
    rep(i,n){
        sort(dp[i].begin(),dp[i].end()); // 二次元めを昇順ソート
    }
    */

    // 整数スキャン（複数）
    /*
    int x,y,z;
    scanf("%d%d%d",&x,&y,&z);

    // n個の整数のスキャン
    /*
    ll a[n] = {};
    rep(i,n){
        scanf("%lld",&a[i]);
    }
    */

    // 文字列スキャン
    /*
    string s; cin >> s;
    */

    // n個の文字列スキャン
    /*
    vector<string> slist;
    rep(i,n){
        string s; cin >> s;
        slist.push_back(s);
    }
    */

int syori(int x, int q, string s, char t[], char d[]){
    rep(i,q){
        if(s[x]==t[i]){
            if(d[i]=='L'){
                x--;
            }else{
                x++;
            }
            if(x==-1){
                return 1;
            }
            if(x==s.size()){
                return 3;
            }
        }
    }
    return 2;
}

int main() {
    int n,q;
    cin >> n >> q;
    string s;
    cin >> s;
    char t[q];
    char d[q];
    rep(i,q){
        cin >> t[i] >> d[i];
    }
    
    int a[n];
    // -1:uncertain 1:fall left 2:stand 3:fall right
    rep(i,n){
        a[i] = -1;
    }


    int l = 0;
    int r = n-1;

    while(true){
        if(a[(l+r)/2]==-1){
            a[(l+r)/2] = syori((l+r)/2,q,s,t,d);
            if(a[(l+r)/2]==1){
                rep(i,(l+r)/2){
                    a[i] = 1;
                }
                l = (l+r)/2+1;
            }
            if(a[(l+r)/2]==3){
                srep(i,(l+r)/2,n){
                    a[i] = 3;
                }
                r = (l+r)/2-1;
            }
            if(a[(l+r)/2]==2){
                r = (l+r)/2-1;
            }
        }else{
            break;
        }
    }
    l = 0;
    r = n-1;
    while(a[l]==1||a[l]==2){
        l++;
    }
    while(true){
        a[(l+r)/2] = syori((l+r)/2,q,s,t,d);
        if(a[(l+r)/2]==2){
            l = (l+r)/2+1;
        }
        if(a[(l+r)/2]==3){
            srep(i,(l+r)/2,n){
                a[i] = 3;
            }
            r = (l+r)/2-1;
        }
        if(r<l)break;
    }

    int ans = n;
    rep(i,n){
        if(a[i]==1||a[i]==3)ans--;
    }
    /*
    rep(i,n){
        cout << a[i];
    }
    cout << endl;
    */
    cout << ans << endl;

    return 0;
}
 
 
