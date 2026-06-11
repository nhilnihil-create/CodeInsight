#include <bits/stdc++.h>

#define MAXN 3005

using namespace std;

const int mod = 1e9 + 7;

int dp[MAXN], pre[MAXN];

int sub(int a, int b) {

    a -= b;
    if(a < 0)
        a += mod;
    return a;
}

int add(int a, int b) {

    a += b;
    if(a >= mod)
        a -= mod;
    return a;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    string s;
    cin >> n >> s;

    dp[1] = 1;
    for(int i = 2; i <= n; i++) {
        for(int j = 1; j < i; j++)
            pre[j] = add(pre[j - 1], dp[j]);
        for(int j = 1; j <= i; j++) {
            if(s[i - 2] == '<')
                dp[j] = pre[j - 1];
            else
                dp[j] = sub(pre[i - 1], pre[j - 1]);
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++)
        ans = add(ans, dp[i]);
    cout << ans << endl;
    return 0;
}
