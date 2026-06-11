#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define CL(x) ((x) * (x))
#define CR(x) (((x) * (x)) + 1)
typedef long long cc;
typedef pair <int, int> pii;
string s;
int res;
int dp[70000007];
int n;

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> s;
    n = s.size();
    for (int i = 1; i < (1 << 26); i++)
        dp[i] = n;
    for (int i = 0; i < n; i++) {
        res ^= (1 << (s[i] - 'a'));
        for (int j = 0; j < 26; j++)
            dp[res] = min(dp[res], dp[res^(1<<j)] + 1);
    }
    if (dp[res])
        cout << dp[res];
    else
        cout << 1;
    return 0;
}
