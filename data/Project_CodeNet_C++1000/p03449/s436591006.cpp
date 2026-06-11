#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using vi = vector<int>;
using vv = vector<vi>;
const int MOD = 1000000007;

int main(){
    int n;cin >>n;
    vv a(2, vi(n));
    
    rep(i,2)rep(j,n)cin>>a[i][j];
    rep(i,n-1)a[0][i+1]+=a[0][i];
    rep(i,n-1)a[1][n-2-i]+=a[1][n-1-i];
    
    int ans = 0;
    rep(i,n)ans = max(ans, a[0][i]+a[1][i]);
    cout << ans << endl;
    
    return 0;
}