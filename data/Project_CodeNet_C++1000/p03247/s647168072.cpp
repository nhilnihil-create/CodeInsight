#include <bits/stdc++.h>
using namespace std;
#define rep(i, n)  for(long long i=0;i<(long long)(n);i++)
#define REP(i,k,n) for(long long i=k;i<(long long)(n);i++)
#define all(a) a.begin(),a.end()
#define pb push_back
#define eb emplace_back
#define lb(v,k) (lower_bound(all(v),k)-v.begin())
#define ub(v,k) (upper_bound(all(v),k)-v.begin())
#define fi first
#define se second
#define pi M_PI
#define PQ(T) priority_queue<T>
#define SPQ(T) priority_queue<T,vector<T>,greater<T>>
#define dame(a) {out(a);return 0;}
#define decimal cout<<fixed<<setprecision(15);
typedef long long ll;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> PP;
typedef tuple<ll,ll,ll,ll> PPP;
typedef multiset<ll> S;
using vi=vector<ll>;
using vvi=vector<vi>;
using vvvi=vector<vvi>;
using vp=vector<P>;
using vvp=vector<vp>;
using vb=vector<bool>;
using vvb=vector<vb>;
const ll inf=1001001001001001001;
const int INF=1001001001;
const int mod=1000000007;
const double eps=1e-10;
template<class T> bool chmin(T&a,T b){if(a>b){a=b;return true;}return false;}
template<class T> bool chmax(T&a,T b){if(a<b){a=b;return true;}return false;}
template<class T> void out(T a){cout<<a<<'\n';}
template<class T> void outp(T a){cout<<'('<<a.fi<<','<<a.se<<')'<<'\n';}
template<class T> void outvp(T v){rep(i,v.size())cout<<'('<<v[i].fi<<','<<v[i].se<<')';cout<<'\n';}
template<class T> void outvvp(T v){rep(i,v.size())outvp(v[i]);}
template<class T> void outv(T v){rep(i,v.size()){if(i)cout<<' ';cout<<v[i];}cout<<'\n';}
template<class T> void outvv(T v){rep(i,v.size())outv(v[i]);}
template<class T> bool isin(T x,T l,T r){return (l)<=(x)&&(x)<=(r);}
template<class T> void yesno(T b){if(b)out("yes");else out("no");}
template<class T> void YesNo(T b){if(b)out("Yes");else out("No");}
template<class T> void YESNO(T b){if(b)out("YES");else out("NO");}
template<class T> void noyes(T b){if(b)out("no");else out("yes");}
template<class T> void NoYes(T b){if(b)out("No");else out("Yes");}
template<class T> void NOYES(T b){if(b)out("NO");else out("YES");}
void outs(ll a,ll b){if(a>=inf-100)out(b);else out(a);}
ll gcd(ll a,ll b){if(b==0)return a;return gcd(b,a%b);}
ll modpow(ll a,ll b){a%=mod;if(b==0)return 1;if(b&1)return a*modpow(a,b-1)%mod;ll k=modpow(a,b/2);return k*k%mod;}

int main(){
    ll n;cin>>n;
    vector<vector<char>> c(2,vector<char>(2));
    c[0][0]='R';c[0][1]='D';c[1][0]='U';c[1][1]='L';
    vp v(n);
    rep(i,n)cin>>v[i].fi>>v[i].se;
    int b=(v[0].fi+v[0].se+inf+1)%2;
    REP(i,1,n)if((v[i].fi+v[i].se+inf+1)%2!=b)dame(-1);
    if(!b)rep(i,n)v[i].fi--;
    rep(i,n)v[i]=P(v[i].fi-v[i].se,v[i].fi+v[i].se);
    if(b)out(31);
    else out(32);
    for(ll k=30;k>=0;k--){
        cout<<(1<<k);
        if(k)cout<<' ';
        else if(b)cout<<endl;
        else cout<<' '<<1<<endl;
    }
    rep(i,n){
        for(ll k=30;k>=0;k--){
            int a=1,d=1;
            if(v[i].fi>=0){
                a=0;v[i].fi-=1<<k;
            }
            else v[i].fi+=1<<k;
            if(v[i].se>=0){
                d=0;v[i].se-=1<<k;
            }
            else v[i].se+=1<<k;
            cout<<c[a][d];
        }
        if(!b)out('R');
        else cout<<endl;
    }
}