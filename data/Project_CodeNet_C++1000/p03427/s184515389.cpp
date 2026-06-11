#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
using namespace std;
int main(){
    long long n,ans=0,ans2=0;
    cin>>n;
    while(n>=10){
        ans+=n%10;
        ans2+=9;
        n/=10;
    }
    ans+=n;
    ans2+=n-1;
    cout<<max(ans,ans2)<<endl;
    return 0;
}
