#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
#define f2(i,j,k) for(int i=j;i>k;i--)
using namespace std;
int main(){
    long long n,ans=0,a;
    cin>>n;
    f(i,0,n){
        cin>>a;
        ans+=a-1;
    }
    cout<<ans<<endl;
    return 0;
}
