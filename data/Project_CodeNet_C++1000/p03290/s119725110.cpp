#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007

using namespace std;



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll d,g,ans=INT_MAX;//cout<<ceil((700-0)/(200+0.0))<<endl;
    cin>>d>>g;
    ll p[11],c[11];
    for(int i=0;i<d;i++)cin>>p[i]>>c[i];
    for(int i=0;i<(1<<d);i++){
        ll s=0,num=0,restmax=-1;
        for(int j=0;j<d;j++){
            if(i>>j & 1){
                s+=100*(j+1)*p[j]+c[j];
                num+=p[j];
            }
            else restmax=j;
        }
        if(s<g){
            ll s1=100*(restmax+1);if(s1==0)continue;
            ll need=ceil((g-s)/(s1+0.0));
            if(need>=p[restmax])continue;
            num+=need;
        }
        ans=min(ans,num);
    }
    cout<<ans<<endl;
}
