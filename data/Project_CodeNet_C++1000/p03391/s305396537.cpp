#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n],b[n];
    long long ans=0ll;
    int mn=1e9+5;
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
        ans+=a[i];
        if(a[i]>b[i]){
            mn=min(mn,b[i]);
        }
    }
    cout<<ans-(mn==1e9+5?ans:mn)<<endl;
    return 0;
}