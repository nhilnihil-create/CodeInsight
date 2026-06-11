#include <iostream>

#define rep(i,n) for(int i=0;i<n;++i)

using namespace std;
using ll = long long;

int main()
{
    int D,G,p[10],c[10];
    cin>>D>>G;
    rep(i,D){
        cin>>p[i]>>c[i];
    }
    int ans=1e9;
    rep(mask,(1<<D)){
        int s=0,num=0,rest_max=-1;
        rep(i,D){
            if(mask&(1<<i)){
                s+=100*(i+1)*p[i]+c[i];
                num+=p[i];
            }else{
                rest_max=i;
            }
        }
        if(s<G){
            int s1 = 100*(rest_max+1);
            int need = (G-s+s1-1)/s1;
            if(need>=p[rest_max]){
                continue;
            }
            num+=need;
        }
        ans = min(ans,num);
    }
    cout << ans << endl;
    return 0;
}