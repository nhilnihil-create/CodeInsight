#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
#define int long long
using P = pair<int,int>;
signed main(){
    int n;cin >> n;
    int a[n],b[n];
    rep(i,n)cin >> a[i];
    rep(i,n)cin >> b[i];
    int ans = 0;
    rep(i,n){
        int res = 0;
        for(int j = 0;j <= i;j++)res += a[j];
        for(int j = i;j < n;j++)res += b[j];
        ans = max(ans,res);

    }
    cout << ans;
    return 0;
}