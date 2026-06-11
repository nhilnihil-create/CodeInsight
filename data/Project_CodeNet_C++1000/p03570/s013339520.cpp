/**
  *  Worg
  */
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

//FILE *fin = freopen("main.in", "r", stdin); FILE *fout = freopen("main.out", "w", stdout);

using namespace std;

const int sigma = 26;

string s;
int dp[1 << sigma];

int main() {
    cin >> s;
    dp[0] = 1;

    int act = 0, crtBest = 0;
    for(int i = 0; i < (int)s.size(); i++) {
        act ^= (1 << (s[i] - 'a'));

        crtBest = i + 1;

        if(dp[act] != 0) {
            crtBest = dp[act];
        }

        for(int j = 0; j < sigma; j++) {
            if(dp[act ^ (1 << j)] != 0 && dp[act ^ (1 << j)] < crtBest) {
                crtBest = dp[act ^ (1 << j)];
            }
        }

        if(dp[act] == 0 || dp[act] > crtBest + 1) {
            dp[act] = crtBest + 1;
        }
    }

    cout << crtBest;
	return 0;
}
