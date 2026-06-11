//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;
 
const int maxn = 5e3 + 10;
const long long max_val = 1LL << 62;
 
long long dp[maxn * 2], dp_min[maxn * 2];
int p[maxn];
 
long long cost(int p1, int p2, int A, int B) {
    if (p1 == p2) return 0;
    else if (p1 > p2) return B;
    else return A;
}
 
int main()
{
    int N, A, B, x;
    cin >> N >> A >> B;
    for (int i = 1; i <= N; i++) {
        cin >> x;
        p[x] = i;
    }
    for (int i = 1; i <= N; i++) for (int j = 0; j <= N; j++) dp[j] = max_val;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <=  N; j++) {
            dp[j] = dp_min[j] + cost(p[i], j, A, B);
        }
        dp_min[0] = dp[0];
        for (int j = 1; j <=  N; j++) dp_min[j] = min(dp_min[j - 1], dp[j]);
    }
    cout << dp_min[ N] << endl;
    return 0;
}