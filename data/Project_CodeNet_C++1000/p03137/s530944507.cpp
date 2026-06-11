#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
#define int long long
using P = pair<int,int>;
signed main(){
    int n,m;cin >> n >> m;
    int x[m];
    rep(i,m)cin >> x[i];
    if(n >= m){
        cout << 0 << endl;
        return 0;
    }
 
    vector<int> res;
    sort(x,x+m);
    int ans = 0;
    rep(i,m-1){
        ans += x[i+1] - x[i];
        res.push_back(x[i+1] - x[i]);
    }
    sort(res.rbegin(),res.rend());
    rep(i,n-1)ans -= res[i];
    cout << ans << endl;

    return 0;
}