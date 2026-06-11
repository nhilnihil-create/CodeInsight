#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m;cin>>n>>m;
    vector<ll> x(n),y(n),z(n);
    rep(i,n)cin>>x[i]>>y[i]>>z[i];
    ll ans=0;
    for(int tmp=0;tmp<1<<3;tmp++){
        bitset<3> s(tmp);
        vector<ll> d(n);
        int po[3];
        for(int i=0;i<3;i++){
            if(s.test(i))po[i]=1;
            else po[i]=-1;
        }
        for(int i=0;i<n;i++)d[i]=x[i]*po[0]+y[i]*po[1]+z[i]*po[2];
        sort(d.begin(),d.end(),greater<ll>());
        ll sum=0;
        for(int i=0;i<m;i++)sum+=d[i];
        if(sum>ans)ans=sum;
    }
    cout<<ans<<endl;
    return 0;
}
