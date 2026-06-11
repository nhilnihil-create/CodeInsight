#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
int gcd(int a,int b){
    if(a%b==0) return b;
    else return gcd(b,a%b);
}
int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    rep(i,n)cin>>a[i];
    sort(a.begin(),a.end());
    int ans=a[0];
    rep(i,n){
        ans=gcd(ans,a[i]);
    }
    cout<<ans<<endl;
}
