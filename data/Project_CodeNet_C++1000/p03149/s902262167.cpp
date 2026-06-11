/*
      author : nishi5451
      created: 12.08.2020 11:31:13
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    vector<bool> dp(10,false);
    rep(i,4){
        int n;
        cin >> n;
        dp[n]=true;
    }
    if(dp[1] && dp[4]&& dp[7] && dp[9])
        cout << "YES" << endl;
    else cout <<"NO" << endl;
    return 0;
}