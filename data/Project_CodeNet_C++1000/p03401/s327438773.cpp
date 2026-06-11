#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin>>n;
    vector<int>a(n+1);
    a[0]=0;
    for(int i=1;i<n+1;i++)cin>>a[i];
    ll saou=0;
    for(int i=1;i<n+1;i++){
        saou+=abs(a[i]-a[i-1]);
    }
    saou+=abs(a[n]);
    for(int i=1;i<n+1;i++){
        if(i<n){
            ll ans=saou-abs(a[i-1]-a[i])-abs(a[i+1]-a[i])+abs(a[i+1]-a[i-1]);
            cout<<ans<<endl;
        }
        else{
            ll ans=saou-abs(a[n])-abs(a[n]-a[n-1])+abs(a[n-1]);
            cout<<ans<<endl;
        }
    }
}
    