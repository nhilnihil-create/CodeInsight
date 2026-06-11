#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int N = 200005;

int n,dp[N],best[ 1 << 26];
string s;

int main(void){
    cin >> s;
    n = s.size();
    
    for(int i = 0; i < 1 << 26; i++){
        best[i] = 1e9;
    }
    best[0] = 0;
    int mask = 0;
    
    for(int i = 0; i < n; i++){
        mask ^= 1 << s[i] - 'a';
        
        dp[i] = best[mask] + 1;
        for(int j = 0; j < 26; j++){
            dp[i] = min(dp[i],best[mask ^ 1 << j] + 1);
        }
        
        best[mask] = min(best[mask],dp[i]);
    }
    /*
    for(int i = 0; i < n; i++){
        cout << dp[i] << " ";
    }
    cout << endl;
    */
    cout << dp[n-1] << endl;
    
    
}
