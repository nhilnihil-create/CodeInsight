#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;
int main(){
    int n;
    cin>>n;
    n--;
    vector<int>c(n),s(n),f(n);
    rep(i,n)cin>>c[i]>>s[i]>>f[i];
    rep(i,n){
        int x=c[i]+s[i];
        for(int j=i+1; j<n; ++j){
            if(x<s[j])x=s[j];
            if((x-s[j])%f[j]!=0)x+=f[j]-((x-s[j])%f[j]);
            x+=c[j];
        }
        cout<<x<<endl;
    }
    cout<<0<<endl;
    return 0;
}