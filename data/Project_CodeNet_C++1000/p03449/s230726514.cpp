#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
int main(){
	cin.tie(0);
    ios::sync_with_stdio(false);
    long long n,a1[105]={};
    long long a2[105],ans=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a1[i];
        if(i!=0)
            a1[i]+=a1[i-1];
    }
    for(int i=0;i<n;i++){
        cin>>a2[i];
    }
    for(int i=n-2;i>=0;i--){
        a2[i]+=a2[i+1];
    }
    for(int i=0;i<n;i++){
        if(ans<a1[i]+a2[i])
            ans=a1[i]+a2[i];
    }
    cout<<ans<<endl;
    return(0);
}