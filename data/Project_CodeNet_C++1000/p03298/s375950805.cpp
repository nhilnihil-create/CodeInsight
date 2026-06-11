#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <cassert>
#include <cmath>
using namespace std;

int main() {
        int n;
        scanf("%d", &n);
        string s;
        cin >> s;
        map<pair<string, string>, int> cnt;
        string hoge = s.substr(0, n);
        string fuga = s.substr(n, n);
        reverse(fuga.begin(), fuga.end());
        for (int i = 0; i < (1 << n); i ++) {
                string unko = "";
                for (int j = 0; j < n; j ++) {
                        if ((i >> j) & 1) {
                                unko += hoge[j];
                        }
                }
                string unko2 = "";
                for (int j = n - 1; j >= 0; j --) {
                        if (!((i >> j) & 1)) {
                                unko2 += hoge[j];
                        }
                }
                cnt[make_pair(unko, unko2)] ++;
        }
        long long ans = 0;
        for (int i = 0; i < (1 << n); i ++) {
                string unko = "";
                for (int j = 0; j < n; j ++) {
                        if ((i >> j) & 1) {
                                unko += fuga[j];
                        }
                }
                string unko2 = "";
                for (int j = n - 1; j >= 0; j --) {
                        if (!((i >> j) & 1)) {
                                unko2 += fuga[j];
                        }
                }
                ans += cnt[make_pair(unko, unko2)];
        }
        printf("%lld\n", ans);
        return 0;
}
