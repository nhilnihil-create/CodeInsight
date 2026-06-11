#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using P = pair<int,int>;
int main()
{
    int x,y,z,k;
    cin >> x >>y >>z >>k;
    vector<ll> a(x),b(y),c(z);
    rep(i,x)cin >> a[i];
    rep(i,y)cin >> b[i];
    rep(i,z)cin >> c[i];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    sort(c.begin(),c.end());
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    reverse(c.begin(),c.end());
    vector<ll> ans;
    rep(i,x)rep(j,y)rep(l,z){
        if(i*j*l > k+1)break;
        ans.push_back(a[i]+b[j]+c[l]);


    }
    sort(ans.begin(),ans.end());
    reverse(ans.begin(),ans.end());
    rep(i,k)cout << ans[i] << endl;
   
    
    return 0;
}