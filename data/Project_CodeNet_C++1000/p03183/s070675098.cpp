#include <bits/stdc++.h>
#define F(i,n) for (int i=1; i<=(int)n; i++)
#define FF(i,n) for (int i=0; i<(int)n; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define pi pair < int , int >
#define re(x) (int)x.size()
#define y1 u228
using namespace std;
typedef long long ll;
const int N = 1010;
const int big = 2e9;
const int md = 1e9 + 7;
int n,w[N],s[N],v[N],p[N],ww[N],ss[N],vv[N],mx;
ll f[N][N*10];
bool cmp(int x,int y){
    return min(s[x]-w[y],s[y])>min(s[y]-w[x],s[x]);
    //return min(s[x]+w[x])>(s[y]+w[y]);
}
void up(ll &x,ll y){x=max(x,y);}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    //freopen("input.txt","r",stdin);
    cin>>n;
    F(i,n) cin>>w[i]>>s[i]>>v[i];
    F(i,n) p[i]=i;
    sort(p+1,p+n+1,cmp);
    F(i,n) {ww[i]=w[p[i]];ss[i]=s[p[i]];vv[i]=v[p[i]];}
    F(i,n) {w[i]=ww[i]; s[i]=ss[i]; v[i]=vv[i];}
    F(i,n) mx=max(mx,s[i]);
    up(f[1][s[1]],0ll+v[1]);
    F(i,n-1){
        FF(j,mx+1){
            if (w[i+1]<=j) up(f[i+1][min(j-w[i+1],s[i+1])],f[i][j]+0ll+v[i+1]);
            up(f[i+1][j],f[i][j]);
        }
        up(f[i+1][s[i+1]],0ll+v[i+1]);
    }
    ll ans=0;
    FF(j,mx+1) ans=max(ans,f[n][j]);
    cout<<ans<<endl;
    return 0;
}





