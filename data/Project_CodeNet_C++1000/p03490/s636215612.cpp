#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <iostream>
#include <bitset>
using namespace std;

int main() {
        string s;
        cin >> s;
        int x, y;
        scanf("%d %d", &x, &y);
        int cnt = 0;
        vector<int> lr, ud;
        int p = 0;
        while (s[p] == 'F') {
                p ++;
                x --;
        }
        bool is_lr = true;
        for (; p < s.size(); p ++) {
                if (s[p] == 'F') { 
                        cnt ++;
                } else {
                        if (cnt) (is_lr ? lr : ud).push_back(cnt);
                        cnt = 0;
                        is_lr = !is_lr;
                }
        }
        if (cnt) (is_lr ? lr : ud).push_back(cnt);
        auto calc = [&](int target, const vector<int> &a) {
                const int MID = 20000;
                bitset<MID * 2> cur, prev;
                prev[MID] = 1;
                for (int i = 0; i < a.size(); i ++) {
                        cur |= prev << a[i];
                        cur |= prev >> a[i];
                        prev = cur;
                        cur.reset();
                }
                return prev[target + MID];
        };
        bool ans = calc(x, lr) && calc(y, ud);
        puts(ans ? "Yes" : "No");
        return 0;
}
