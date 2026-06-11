#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
#define f2(i,j,k) for(int i=j;i>k;i--)
using namespace std;
int main(){
    long long a[3],ans=0;
    cin>>a[0]>>a[1]>>a[2];
    sort(a,a+3);
    if((a[1]-a[0])%2==0){
        ans+=(a[1]-a[0])/2+a[2]-a[1];
    }
    else if((a[1]-a[0])%2!=0){
        ans+=(a[1]-a[0]-1)/2+a[2]-a[1]+2;
    }
    cout<<ans<<endl;
    return 0;
}
