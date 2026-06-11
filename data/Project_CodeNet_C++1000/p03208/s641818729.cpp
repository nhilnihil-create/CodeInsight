#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
using namespace std;
int main(){
    long long k,n,ans=1000000000;
    cin>>n>>k;
    long long h[n];
    f(i,0,n){
        cin>>h[i];
    }
    sort(h,h+n);
    f(i,0,n-k+1){
        ans=min(h[i+k-1]-h[i],ans);
    }
    cout<<ans<<endl;
    return 0;
}
