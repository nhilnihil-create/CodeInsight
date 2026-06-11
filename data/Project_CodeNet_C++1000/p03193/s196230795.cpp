#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;
int main(){
    int n,h,w;
    cin>>n>>h>>w;
    vector<int>a(n),b(n);
    int ans=0;
    rep(i,n){
        cin>>a[i]>>b[i];
        if(h<=a[i]&&w<=b[i])ans++;
    }
    cout<<ans<<endl;
}