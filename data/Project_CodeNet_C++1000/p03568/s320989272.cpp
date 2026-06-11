#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
#define f2(i,j,k) for(int i=j;i>k;i--)
using namespace std;
int main(){
    long long n,ans=1,ans2=1;
    cin>>n;
    long long x;
    f(i,0,n){
        cin>>x;
        if(x%2==0){
            ans*=2;
        }
        else{
            ans*=1;
        }
        ans2*=3;
    }
    cout<<ans2-ans<<endl;
    return 0;
}
