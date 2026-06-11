#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n,k;
    cin>>n>>k;
    vector<long long int>a(n);
   
    rep(i,n)cin>>a[i];
    sort(a.begin(),a.end());
    long long int ans=1000000000;
    rep(i,n-k+1){
        long long int now=a[i+k-1]-a[i];
        ans=min(ans,now);

    }
    
    cout<<ans<<endl;
}