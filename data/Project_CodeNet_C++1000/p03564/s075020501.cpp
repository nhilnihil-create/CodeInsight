#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
int main(){
	cin.tie(0);
    ios::sync_with_stdio(false);
    int n,k,ans=1;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        ans=min(ans*2,ans+k);
    }
    cout<<ans<<endl;
    return(0);
}