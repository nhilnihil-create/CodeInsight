#include <bits/stdc++.h>
using namespace std;

using ll = long long; 

const int mod = 1e9+7;

const int nax = 3005;

int dp[nax][nax];

char cmp[nax];

int add(int a, int b) {
    int c = a + b;
    if (c >= mod) {
        c -= mod;
    }
    return c;
}

int subtract(int a, int b) {
    int c = a - b;
    if (c < 0) {
        c += mod;
    }
    return c;
}

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", cmp);
    vector<int> pref_sum = vector<int>(n+1);
    dp[1][1] = 1;
    pref_sum[1] = 1;
    for (int len = 2; len <= n; len++) {
        for (int b = 1; b <= n; b++) {
            int L, R;
            if (cmp[len-2] == '<') {
                L = 1;
                R = b-1;
            }
            else {
                L = b;
                R = len-1;
            }
            dp[len][b] = add(dp[len][b], subtract(pref_sum[R], pref_sum[L-1]));
        }
        for (int b = 1; b <= n; b++) {
            pref_sum[b] = add(dp[len][b], pref_sum[b-1]);
        }
    }
    int answer = pref_sum[n];
    printf("%d", answer);
	return 0;
}


/*
nax = 3005
dp = [[0 for _ in range(nax)] for _ in range(nax)]
mod = 1e9+7
def add(a, b):
    c = a + b
    if c >= mod:
        c -= mod
    return c
def subtract(a, b):
    c = a - b
    if c < 0:
        c += mod
    return c

# dp[i][j] - the number of ways to put numbers in prefix of size 'i'
# such that the last number is 'j'
def main():
    n = int(raw_input())
    s = raw_input()    
    pref_sum = [0 for _ in range(n+1)]
    dp[1][1] = 1
    pref_sum[1] = 1
    for length in range(2, n+1):
        
        for b in range(1, length+1):
            if s[length-2] == '<':
                L = 1
                R = b-1
            else: # == '>'
                L = b
                R = length-1
            
            dp[length][b] = add(dp[length][b], subtract(pref_sum[R], pref_sum[L-1]))
            
            # for i in range(L, R+1):
            #     dp[length][b] = add(dp[length][b], dp[length-1][i])
                
            # for a in range(1, length):
            #     real_a = a
            #     if a >= b:
            #         real_a += 1
            #     if (real_a < b) != (s[length-2] == '<'):
            #         continue
            #     dp[length][b] = add(dp[length][b], dp[length-1][a])
        for b in range(1, length+1):
            pref_sum[b] = dp[length][b]
            pref_sum[b] = add(pref_sum[b], pref_sum[b-1])
        
    answer = 0
    for i in range(1, n+1):
        answer = add(answer, dp[n][i])
    answer = int(answer)
    print(answer)
    
main()

*/