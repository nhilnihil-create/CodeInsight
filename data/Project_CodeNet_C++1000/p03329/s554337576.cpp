#include <bits/stdc++.h>
#include <math.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
using Graph = vector<vector<int>>;
typedef long long ll;
typedef pair<int, int> P;

const int MOD = 1000000007;
const int INF_32 = 1LL << 30;
const int64_t INF_64 = 1LL << 60;

const int MAX_N = 110000;

int memo[MAX_N]; // memo[i]がiについての答え

int rec(int n)
{
    if (n == 0)
        return 0;
    if (memo[n] != -1)
        return memo[n];

    int res = n;
    for (int pow6 = 1; pow6 <= n; pow6 *= 6)
        res = min(res, rec(n - pow6) + 1);
    for (int pow9 = 1; pow9 <= n; pow9 *= 9)
        res = min(res, rec(n - pow9) + 1);

    return memo[n] = res;
}

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < MAX_N; i++)
        memo[i] = -1;
    cout << rec(N) << endl;

    return 0;
}