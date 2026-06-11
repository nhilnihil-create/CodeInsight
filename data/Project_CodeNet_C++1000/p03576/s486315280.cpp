#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll n,k;
    cin>>n>>k;
    ll ans=9e18;
    ll x[n],y[n],a[n+1][n+1],c[n],d[n];
    for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)a[i][j]=0;
    for(int i=0;i<n;i++){
        cin>>x[i]>>y[i];
        c[i]=x[i];
        d[i]=y[i];
    }
    sort(c,c+n);
    sort(d,d+n);
    map<ll,ll> e,f;
    for(int i=0;i<n;i++){
        e[c[i]]=i+1;
        f[d[i]]=i+1;
    }
    for(int i=0;i<n;i++)a[e[x[i]]][f[y[i]]]++;
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)a[i][j]+=a[i][j-1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            a[i][j]+=a[i-1][j];
        }
    }
    ll maki,niko;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int z=0;z<i;z++){
                for(int m=0;m<j;m++){
                    if(a[i][j]-a[z][j]-a[i][m]+a[z][m]>=k){
                        maki=c[i-1]-c[z];
                        niko=d[j-1]-d[m];
                        ans=min(ans,maki*niko);
                    }
                }
            }
        }
    }
    cout << ans<<endl;
    return 0;
}
