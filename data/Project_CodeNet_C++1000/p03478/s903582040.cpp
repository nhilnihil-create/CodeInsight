#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
using namespace std;
int main(){
    long long n,a,b,ans=0,d;
    cin>>n>>a>>b;
    for(int i=1;i<=n;i++){
        d=i/10000+(i/1000)%10+(i%1000)/100+(i%100)/10+i%10;
        if(d>=a&&d<=b){
            ans+=i;
        }
    }
    cout<<ans<<endl;
    return 0;
}
