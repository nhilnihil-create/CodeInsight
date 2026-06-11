/*
      author  : nishi5451
      created : 14.08.2020 23:36:21
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int n,m;
    cin >> n >> m;
    vector<int> dp(m+1);
    rep(i,n){
        int k;
        cin >> k;
        rep(j,k){
            int a;
            cin >> a;
            dp[a]++;
        }
    }
    int ans = 0;
    for(int i=1; i<=m; i++){
        if(dp[i]==n) ans++;
    }
    cout << ans << endl;
    return 0;
}