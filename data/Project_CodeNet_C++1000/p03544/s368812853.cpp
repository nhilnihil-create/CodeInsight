#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
using namespace std;
int main(){
    long long n,ans=1,ans2=2,d;
    cin>>n;
    if(n==1){
        cout<<1<<endl;
    }
    else{
        f(i,0,n-1){
            d=ans;
            ans+=ans2;
            ans2=d;
        }
        cout<<ans<<endl;
    }
    return 0;
}
