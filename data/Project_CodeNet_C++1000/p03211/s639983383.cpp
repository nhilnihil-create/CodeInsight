#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9; //1(1倍)e(指数)9(10^9)
int main()
{
    string s;
    cin >> s;
    int n = s.size();
    int ans = inf;
    for(int i = 0; i < n - 2; i++) {
        int temp = abs((s[i] - '0') * 100 + (s[i + 1] - '0') * 10 + (s[i + 2] - '0') - 753);
        ans = min(ans, temp);
    }
    printf("%d\n", ans);
    return 0;
}
