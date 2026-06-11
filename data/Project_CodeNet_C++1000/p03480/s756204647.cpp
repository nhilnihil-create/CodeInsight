#include <bits/stdc++.h>

#define mem(f, v) memset(f,v,sizeof(f))
#define file(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);

typedef long long ll;
const int maxn = 100010;
const int inf = ~(1u << 31u);
const ll linf = ~(1llu << 63u);

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    string str;
    cin >> str;
    str = str;
    int n = str.length(), res = n;
    for (int i = 1; i < n; i++) {
        if (str[i - 1] != str[i])
            res = min(res, max(i, n - i));
    }
    cout << max((n + 1) / 2, res) << endl;
    return 0;
}