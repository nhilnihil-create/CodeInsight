//#pragma GCC optimize("O3")

#include <bits/stdc++.h>

using namespace std;
char str[55];

int main() {
   // freopen("in.txt", "rt", stdin);
    int l;
    scanf("%d", &l);
    int x = l;
    int sz = 0;
    while (x) {
        str[sz] = char('0' + (x % 2));
        x /= 2;
        ++sz;
    }
    str[sz] = 0;
   // printf("%s\n",str);
    vector<pair<int, pair<int, int>>> vec;
    int cnt = str[0] == '1';
    for (int i = 1; i < sz; ++i) {
        vec.push_back({i, {i - 1, 0}});
        vec.push_back({i, {i - 1, (1 << (i - 1))}});
        cnt += str[i] == '1';
    }
    if (cnt != 1) {
        int cur = l;
        for (int i = 0; i + 1 < sz; ++i) {
            if (str[i] == '1') {
                vec.push_back({sz-1, {i, cur - (1 << (i))}});
                cur -= (1 << (i));
            }
        }
    }
    printf("%d %d\n", sz, (int) vec.size());
    for (auto e:vec) {
        printf("%d %d %d\n", sz - e.first, sz - e.second.first, e.second.second);
    }
}