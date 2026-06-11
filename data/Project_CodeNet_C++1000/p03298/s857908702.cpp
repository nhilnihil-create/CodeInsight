#include <map>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

long long ret;
map<pair<string, string>, int> cnt;

void solve()
{
    int n;
    ret = 0;
    string s;
    cin >> n >> s;
    for (int mask = 0; mask < (1 << n); mask++) {
        string a, b;
        for (int i = 0; i < n; i++) {
            if (mask >> i & 1) a += s[i];
            else b += s[i];
        }
        cnt[make_pair(a, b)]++;
    }
    for (int mask = 0; mask < (1 << n); mask++) {
        string a, b;
        for (int i = 0; i < n; i++) {
            if (mask >> i & 1) a += s[n + n - 1 - i];
            else b += s[n + n - 1 - i];
        }
        ret += cnt[make_pair(a, b)];
    }
    cout << ret << endl;
}

int main()
{
    solve();
    return 0;
}

