#include<bits/stdc++.h>
#define int long long
int a[114514];
int b[114514];
using namespace std;
signed main(){
    int n,h,w;
    cin>>n>>h>>w;
    for(int i=0;i<n;i++){
        cin>>a[i];
        cin>>b[i];
    }
    int ans=0;
    for(int i=0;i<n;i++){
        if(a[i]>=h&&b[i]>=w){
            ans++;
        }
    }
    cout<<ans<<endl;
}