#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
int main(){
	cin.tie(0);
    ios::sync_with_stdio(false);
    long long n,a,ans=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        ans+=a-1;
    }
    cout<<ans<<endl;
    return(0);
}