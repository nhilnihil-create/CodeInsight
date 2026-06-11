#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;
int main(){
    int n; string a,b,c;
    cin>>n>>a>>b>>c;
    int ans=0;
    rep(i,n){
        if(a[i]!=b[i]){
            ans++;
        }
        if(b[i]!=c[i]){
            ans++;
            if(c[i]==a[i]){
                ans--;
            }
        }
    }
    cout<<ans<<endl;
}
