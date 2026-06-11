#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll d,g;
ll p[15],c[15];
ll ans=10000000000000000;
int main(void){
    cin>>d>>g;
    for(int i=0;i<d;i++){
        cin>>p[i]>>c[i];
    }
    for(int bit=0;bit<(1<<d);bit++){
        ll cnt=0;
        ll C=0;
        for(int i=0;i<d;i++){
            if(bit&(1<<i)){
                cnt+=(i+1)*100*p[i]+c[i];
                C+=p[i];
            }
        }
        int i=d-1;
        while(cnt<g&&i>=0){
            if((bit&(1<<i))==0){
                if(g-cnt>(i+1)*100*(p[i]-1)){
                    cnt+=(i+1)*100*(p[i]-1);
                    C=C+p[i]-1;
                }else{
                    C=C+(g-cnt+(i+1)*100-1)/((i+1)*100);
                    cnt=g;
                }
            }
            i--;
        }
        if(cnt>=g){
            ans=min(ans,C);
        }
    }
    cout<<ans<<endl;
    
}
