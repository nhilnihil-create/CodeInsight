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
    string s;
    cin >> s;
    s = s + 'A';
    //cout << s << endl;
    int ss = s.size();
    int x;
    scanf("%d",&x);
    int y;
    scanf("%d",&y);

    int a[5000] = {};
    int b[5000] = {};
    int turna = 0;
    int counta = 0;
    int turnb = 0;
    int countb = 0;
    int ii = 0;
    int count = 0;
    int head = 1;
    while(s[ii]=='F'){
        count++;
        ii++;
    }
    a[turna] = count;
    turna++;
    counta += count;
    for(;;){
        if(s[ii]=='A'){
            break;
        }else if(s[ii]=='T'){
            head *= -1;
            ii++;
        }else if(s[ii]=='F'){
            count = 0;
            while(s[ii]=='F'){
                count++;
                ii++;
            }
            if(head==1){
                a[turna] = count;
                turna++;
                counta += count;
            }else{
                b[turnb] = count;
                turnb++;
                countb += count;
            }
        }
    }

    //ここから動的計画法
    int dpx[turna][counta*2+1];
    rep(i,turna){
        rep(j,counta*2+1){
            dpx[i][j]=0;
        }
    }
    rep(i,turna){
        if(i==0){
            rep(j,counta*2+1){
                dpx[0][j] = 0;
            }
            dpx[0][counta+a[0]] = 1;
        }else{
            rep(j,counta*2+1){
                int temp=0;
                if(j-a[i]<=counta*2&&j-a[i]>=0){
                    maxs(temp,dpx[i-1][j-a[i]]);
                }
                if(j+a[i]<=counta*2&&j+a[i]>=0){
                    maxs(temp,dpx[i-1][j+a[i]]);
                }
                dpx[i][j] = temp;
            }
        }
        /*
        rep(j,counta*2+1){
            cout << dpx[i][j];
        }
        cout << endl;
        */
    }

    int ans1 = 0;
    ans1 = dpx[turna-1][counta+x];
    if(counta==0&&x==0){
        ans1=1;
    }

    int dpy[turnb][countb*2+1];
    rep(i,turnb){
        rep(j,countb*2+1){
            dpy[i][j]=0;
        }
    }
    rep(i,turnb){
        if(i==0){
            rep(j,countb*2+1){
                dpy[0][j] = 0;
            }
            dpy[0][countb+b[0]] = 1;
            dpy[0][countb-b[0]] = 1;
        }else{
            rep(j,countb*2+1){
                int temp=0;
                if(j-b[i]<=countb*2&&j-b[i]>=0){
                    maxs(temp,dpy[i-1][j-b[i]]);
                }
                if(j+b[i]<=countb*2&&j+b[i]>=0){
                    maxs(temp,dpy[i-1][j+b[i]]);
                }
                dpy[i][j] = temp;
            }
        }
        /*
        rep(j,countb*2+1){
            cout << dpy[i][j];
        }
        cout << endl;
        */
    }

    int ans2 = 0;
    ans2 = dpy[turnb-1][countb+y];
    if(countb==0&&y==0){
        ans2=1;
    }

    if(ans1==1&&ans2==1)yn;

    //cout << ans << endl;

    return 0;
}
 
 
