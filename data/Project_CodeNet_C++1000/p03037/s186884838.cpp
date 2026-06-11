#include <bits//stdc++.h>
#define rep(i,n) for(int i = 0;i < n;i++)
using namespace std;
typedef long long ll;

int main(){
    int n,m;
    cin>>n>>m;
    int b,s,l=0,r=1000000;
    rep(i,m){
        cin>>s>>b;
        l=max(s,l);
        r=min(b,r);
    }
    int ans=min(n-l+1,r-l+1);
    if(ans>=0)cout<<ans<<endl;
    else cout<<'0'<<endl;
    return 0;
}