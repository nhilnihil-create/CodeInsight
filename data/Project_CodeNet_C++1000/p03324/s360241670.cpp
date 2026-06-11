#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
#define f2(i,j,k) for(int i=j;i>k;i--)
using namespace std;
int main(){
    long long n,d,ans;
    cin>>d>>n;
    if(n==100){
        ans=101*pow(100,d);
    }
    else{
        ans=n*pow(100,d);
    }
    cout<<ans<<endl;
    return 0;
}
