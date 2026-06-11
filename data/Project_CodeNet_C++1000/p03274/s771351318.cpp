#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
    int n,k;cin>>n>>k;
    vector<int> x(n);
    ll ans=1e18;
    for(int i=0;i<n;i++) cin>>x[i];
    for(int l=0;l<n-k+1;l++){
        int r=l+k-1;
        ll time;
        if(x[l]<0&&x[r]<=0) time=abs(x[l]);
        else if(x[l]>=0&&x[r]>0) time=x[r];
        else time=x[r]+abs(x[l])+min(x[r],abs(x[l]));
        ans=min(ans,time);
    }
    cout<<ans<<endl;
}