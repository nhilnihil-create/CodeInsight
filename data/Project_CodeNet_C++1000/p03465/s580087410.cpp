#include <bits/stdc++.h>
using namespace std;

const int N = 2005, M = N * N;

typedef bitset<M> bs;

int n;
bs dp;

int main() {
    cin >> n;
    dp[0] = true;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        sum += x;
        dp |= (dp << x);
    }
    for(int cur = (sum + 1) / 2; ; cur++) {
        if(dp[cur]) {
            cout << cur << endl;
            return 0;
        }
    }
}