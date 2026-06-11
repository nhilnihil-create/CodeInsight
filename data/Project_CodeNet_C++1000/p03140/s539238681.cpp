#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;
int main(){
    int n; string a,b,c;
    cin>>n>>a>>b>>c;
    int ans=0;
    rep(i,n){
        ans+=(a[i]==b[i]&&b[i]==c[i])+(a[i]==b[i]||b[i]==c[i]||c[i]==a[i]);
    }
    cout<<2*n-ans<<endl;
}
