#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long LL;

const string temp = "AKIHABARA";

int vis[26];

int main() {
   // freopen("in.txt", "r", stdin);
    string s;
    cin >> s;
    int n = s.length(), m = 0;
    for (int i = 0; i < n; i++) {
        vis[s[i] - 'a'] ++;
        m = max(m, vis[s[i] - 'a']);
    }
    puts((m - 1) * 3 + 1 <= n ? "YES" : "NO");
    return 0;
}
