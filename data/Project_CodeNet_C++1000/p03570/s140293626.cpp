#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int INF = (1 << 30);

int main(){
    string S;
    while(cin >> S){
        vector<int> dp(1<<26, INF);
        dp[0] = 0;
        int h = 0;
        int res = 0;
        for(auto c : S){
            h ^= 1 << (c - 'a');
            res = dp[h] + 1;
            for(int i=0;i<26;i++){
                int t = h^(1<<i);
                res = min(res, dp[t] + 1);
            }
            dp[h] = min(dp[h], res);
        }
        cout << res << endl;
    }
}