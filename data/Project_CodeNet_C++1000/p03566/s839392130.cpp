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
    ll n;cin>>n;
    ll t[n+1];
    double v[n+2],m;
    t[0]=v[0]=v[n+1]=0;
    for(int i=1;i<=n;i++){cin>>t[i];t[i]*=2;t[i]+=t[i-1];}
    ll tmax=t[n];vector<double> ans(tmax+1,1e18);
    for(int i=1;i<=n;i++){
        cin>>v[i];v[i]*=2;
        m=0;
        for(ll j=t[i-1];j>=0;j--,m++)ans[j]=min(ans[j],v[i]+m);
        for(ll j=t[i-1];j<=t[i];j++)ans[j]=min(ans[j],v[i]);
        m=0;
        for(ll j=t[i];j<=tmax;j++,m++)ans[j]=min(ans[j],v[i]+m);
    }
    m=0;
    for(ll i=0;i<=tmax;i++,m++){
        ans[i]=min(ans[i],m);
    }
    m=0;
    for(ll i=tmax;i>=0;i--,m++){
        ans[i]=min(ans[i],m);
    }
    double sum=-ans[tmax]-ans[0];
    for(int i=0;i<=tmax;i++)sum+=ans[i]*2;
    doublecout(sum/8);
    return 0;
}