#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
const int INF=2012345678;
const ll LLINF=4012345678012345678LL;
const ll MOD=998244353; //1000000007
const ld PI=3.1415926535898;
const ld EPS=1e-9;
ll gcd(ll a,ll b){if(a<b)swap(a,b);if(b==0)return a;return gcd(b,a%b);}
inline ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
inline ll expo(ll b,ll p,ll m){ll res=1; while(p){if(p&1)res=(res*b)%m; b=(b*b)%m; p>>=1;} return res;}
inline ll modinv(ll a,ll m){return expo(a,m-2,m);}

struct node{
    int s,e,m;
    ll v;
    node *l,*r;
    node(int S,int E){
        s=S;e=E;m=(s+e)/2;v=0;
        if(s!=e){
            l=new node(s,m);r=new node(m+1,e);
        }
    }
    void upd(int x,ll nv){
        if(s==e){v=max(v,nv);return;}
        if(x<=m)l->upd(x,nv);
        else r->upd(x,nv);
        v=max(l->v,r->v);
    }
    ll qry(int x){ //pref max
        if(x==e)return v;
        if(x<=m)return l->qry(x);
        return max(l->qry(m),r->qry(x));
    }
}*root;

int main(){
    int n;
    scanf("%d",&n);
    int h[n];ll arr[n];
    for(int i=0;i<n;i++)scanf("%d",&h[i]);
    for(int i=0;i<n;i++)scanf("%lld",&arr[i]);
    root=new node(0,n);
    for(int i=0;i<n;i++){
        ll ans=root->qry(h[i]-1);
        root->upd(h[i],ans+arr[i]);
    }
    printf("%lld",root->qry(n));
}
