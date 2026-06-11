#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string s;
int data[200010];
int opt[200010];
int dp[1 << 26];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> s;

    for(size_t i = 1; i <= s.size(); ++i){
        data[i] = data[i - 1] ^ (1 << int(s[i - 1] - 'a'));
    }
    
    for(int i = 0; i < (1 << 26); ++i){
        dp[i] = 1 << 29;
    }

    opt[0] = 1 << 29;
    dp[0] = 0;
    for(size_t i = 1; i <= s.size(); ++i){
        opt[i] = dp[data[i]] + 1;
        for(int j = 0; j < 26; ++j){
            opt[i] = min(opt[i], dp[data[i] ^ (1 << j)] + 1);
        }
        dp[data[i]] = min(dp[data[i]], opt[i]);
    }

    cout << opt[s.size()] << endl;

    return 0;
}