#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    vector <int> dp(m+1,0);
    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        for(int j = 0; j < k; j++){
            int tmp;
            cin >> tmp;
            dp[tmp]++;
        }
    }
    int ans = 0;
    for(int i = 1; i <= m; i++){
        if(dp[i]==n)ans++;
    }
    cout << ans << endl;
    return 0;
}