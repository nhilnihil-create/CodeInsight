#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;
int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    rep(i,n){
        cin>>a[i];
    }
    int ans=0;
    rep(i,n-1){
        if(a[i]==a[i+1]){
            for(int j=1; j<=10000; ++j){
                if(a[i]!=j&&a[i+1]!=j){
                    a[i+1]=j;
                }
            }
            ans++;
        }
    }
    cout<<ans<<endl;
}