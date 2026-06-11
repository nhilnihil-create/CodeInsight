#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int x,y,z,k;
    cin>>x>>y>>z>>k;
    vector<ll>a(x),b(y),c(z);
    rep(i,x)cin>>a[i];
    rep(i,y)cin>>b[i];
    rep(i,z)cin>>c[i];
    vector<ll>sum;
    rep(i,x)rep(j,y){
        sum.push_back(a[i]+b[j]);
    }
    sort(sum.rbegin(),sum.rend());
    vector<ll>ans;
    rep(i,min(k,x*y)){
        rep(j,z){
            ans.push_back(sum[i]+c[j]);
        }
    }
    sort(ans.rbegin(),ans.rend());
    rep(i,k)cout<<ans[i]<<endl;
}