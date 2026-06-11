#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;

int main(){
    int n,m;
    string s,t;
    cin>>n>>m>>s>>t;
    ll g=__gcd(n,m);
    ll ans=n/g*m;
    for(int i=0,j=0; i<n; i+=n/g,j+=m/g){
        if(s[i]!=t[j])ans=-1;
    }
    cout<<ans<<endl;
    return 0;
}
