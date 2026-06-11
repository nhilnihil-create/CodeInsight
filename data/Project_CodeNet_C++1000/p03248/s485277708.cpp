#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;
char str[N];
pair<int, int> ans[N];
bool vis[N];

int main() {
    //freopen("in.txt", "rt", stdin);
    vector<int> ones;
    scanf("%s", str);
    int n = strlen(str);
    if (str[0] == '1') ones.push_back(1);
    else {
        puts("-1");
        return 0;
    }
    if (str[n - 1] == '1') {
        puts("-1");
        return 0;
    }
    for (int i = 2; i < n; ++i) {
        if (str[i - 1] != str[n - i - 1]) {
            puts("-1");
            return 0;
        }
    }

    for (int i = 1; i < n; ++i) {
        if (str[i - 1] == '1') {
            ones.push_back(i);
        }
    }
    vector<pair<int, int>> vec;
    ones.push_back(n);
    for (int i = 1; i < ones.size(); ++i) {
        int a = ones[i], b = ones[i - 1];
        for (int j = b; j < a; ++j) {
            vec.push_back({j, a});
        }
    }
    for (auto x:vec) {
        printf("%d %d\n", x.first, x.second);
    }
}