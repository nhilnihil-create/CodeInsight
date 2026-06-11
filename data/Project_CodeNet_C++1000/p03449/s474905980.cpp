#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
#define f2(i,j,k) for(int i=j;i>k;i--)
using namespace std;
int main(){
    long long n,ans=0;
    cin>>n;
    long long a[n],b[n];
    f(i,0,n){
        cin>>a[i];
    }
    f(i,0,n){
        cin>>b[i];
    }
    f(i,1,n){
        a[i]+=a[i-1];
    }
    f2(i,n-1,0){
        b[i-1]+=b[i];
    }
    f(i,0,n){
        ans=max(ans,a[i]+b[i]);
    }
    cout<<ans<<endl;
    return 0;
}
