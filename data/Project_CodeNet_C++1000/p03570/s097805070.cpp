#include<iostream>
#include<map>
#include<cstdio>
#include<vector>

using namespace std;

int dp[67108864]; // 2 ^ 26

#define DPMAX 67108864
#define INF 2000000


string tobin(int n) {
    string s = "";
    for (int i = 31; i >= 0; --i) {
        s += (n >> i) & 1 ? "1" : "0";
    }
    return s;
}

int main() {
    char c;
    int code = 0;
    int i = 1;

    for (int i = 0; i < DPMAX; ++i) {
        dp[i] = INF;
    } 
    dp[0] = 1;
    for (int i = 0; i < 26; ++i) {
        dp[1 << i] = 1;
    } 
    while (scanf("%c", &c)) {
        if (c == '\n') break;
        code = code ^ (1 << (c - 'a'));
        //cout << "i = " << i << " code = " << tobin(code) << endl;
        int ncode = code;
        for (int k = 0; k <= 26; ++k) {
            
            dp[ncode] = min(dp[code] + 1, dp[ncode]);
            //cout << "    ncode = " << tobin(ncode) << " dp = " << dp[ncode] << endl;
            ncode = code ^ (1 << k);
        }
        i += 1;
    }

    cout << dp[code]<< endl;
}