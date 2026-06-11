#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;
int main(){
    int n;
    cin>>n;
    vector<int>a(n),b(n);
    ll cnt1=0,cnt2=0,cnt3=0;
    rep(i,n)cin>>a[i];
    rep(i,n)cin>>b[i];
    rep(i,n){
        cnt1+=a[i];
        cnt2+=b[i];
        if(a[i]<b[i])cnt3+=(b[i]-a[i]+1)/2;
    }
    ll x=cnt2-cnt1;
    if(x>=cnt3)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}