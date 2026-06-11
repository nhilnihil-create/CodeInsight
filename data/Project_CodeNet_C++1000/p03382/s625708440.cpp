#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;cin>>n;
    vector<int> a(n);
    rep(i,n)cin>>a[i];
    int maxi=0,mini=1e9+7,tmp=1e9+7;
    rep(i,n)maxi=max(maxi,a[i]);
    rep(i,n)if(a[i]==maxi)a[i]=0;
    if(maxi%2==0){
        rep(i,n)if(abs(a[i]-maxi/2)<tmp)mini=a[i],tmp=abs(a[i]-maxi/2);
    }
    else {
        rep(i,n){
            if(a[i]<=maxi/2 && abs(a[i]-maxi/2)<tmp)mini=a[i],tmp=abs(a[i]-maxi/2);
            else if(a[i]>maxi/2 && abs(a[i]-maxi/2-1)<tmp)mini=a[i],tmp=abs(a[i]-maxi/2-1);
        }
    }
    cout<<maxi<<' '<<mini<<endl;
    return 0;
}
