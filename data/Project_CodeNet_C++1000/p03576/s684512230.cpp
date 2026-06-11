#include <iostream>
#include <algorithm>
using namespace std;
int n,k,cnt;
long long ans=5e18,x[60],y[60];
int main(){
    cin>>n>>k;
    for(int i=0;i<n;i++)cin>>x[i]>>y[i];
    for(int a=0;a<n;a++){
        for(int b=0;b<n;b++){
            if(x[b]<x[a])continue;
            for(int c=0;c<n;c++){
                for(int d=0;d<n;d++){
                    if(y[d]<y[c])continue;
                    cnt=0;
                    for(int i=0;i<n;i++)if(x[a]<=x[i]&&x[i]<=x[b]&&y[c]<=y[i]&&y[i]<=y[d])cnt++;
                    if(cnt>=k)ans=min(ans,(x[b]-x[a])*(y[d]-y[c]));
                }
            }
        }
    }
    cout<<ans<<endl;
}