#include <bits/stdc++.h>
using namespace std;
int n,a[1<<18],b[1<<18],ans,x,y;
int main(void){
    cin>>n;
    for(int i=0;i<1<<n;i++)cin>>a[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<1<<n;j++){
            if(j&(1<<i)){
                x=a[j^(1<<i)],y=b[j^(1<<i)];
                if(a[j]<x)swap(a[j],x);
                b[j]=max(b[j],max(x,y));
            }
        }
    }
    for(int i=1;i<1<<n;i++){
        ans=max(ans,a[i]+b[i]);
        cout<<ans<<endl;
    }
}
