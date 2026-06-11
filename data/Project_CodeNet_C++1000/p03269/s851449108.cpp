#include <bits/stdc++.h>

using namespace std;
vector<pair<pair<int, int>, int> > vp;

void full_graph(int n) {
    for (int i = 1; i < n; i++) {
        vp.push_back({{i, i + 1}, 0});
        vp.push_back({{i, i + 1}, 1 << (n - i - 1)});
    }
}

int main() {

    int n;
    scanf("%d", &n);

    n--;
    int tmp = n;
    int cnt = 0;
    while (tmp) {
        cnt++;
        tmp /= 2;
    }

    full_graph(cnt);
    tmp = n;
    int cur = 0;
    bool b = 1;
    for (int i = cnt; i >= 0; i--) {
        if (((n >> i) & 1) && !b) {
            vp.push_back({{1, cnt - i}, cur});
            cur |= (1 << i);
        } else if ((n >> i) & 1) {
            cur |= (1 << i);
            b = 0;
        }
    }
    if(n == 1){
        vp.push_back({{1, 2}, 0});
        vp.push_back({{1, 2}, 1});
        cnt = 2;
    }else {
        vp.push_back({{1, cnt}, n});
    }
    printf("%d %d\n", cnt, vp.size());
    for (auto cur : vp) {
        printf("%d %d %d\n", cur.first.first, cur.first.second, cur.second);
    }
}
