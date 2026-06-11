#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000;
int main(){
    int n; cin >> n;
    vector<int> h(n);
    for(int i=0; i<n; ++i){cin >> h[i];}
    vector<int> dp(n); dp[0] = 0; dp[1] = abs(h[1]-h[0]);
    //for(int j=0; j<n; ++j){cout << dp[j] << ",";} cout << endl;
    for(int i=0; i+2<n; ++i){
        dp[i+2] = min(dp[i]+abs(h[i+2]-h[i]), dp[i+1]+abs(h[i+2]-h[i+1]));
        //for(int j=0; j<n; ++j){
        //  	cout << dp[j] << ",";
        //  } cout << endl;
    }
    cout << dp[n-1] << endl;
    return 0;
}