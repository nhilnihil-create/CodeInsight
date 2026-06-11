#include <bits/stdc++.h>
typedef long long int LL;
typedef unsigned long long int ULL;
using namespace std;

// 插入此處

struct Edge {
    int u, v, w;
};

int main() {
    int L;
    cin >> L;
    int high_bit;
    for (int i = 0; i <= 20; i++) {
        if ((1 << i) & L) {
            high_bit = i;
        }
    }
    int n = high_bit + 1;
    vector<Edge> e;
    for (int i = 1; i < n; i++) {
        e.push_back({ i, i + 1, 0 });
        e.push_back({ i, i + 1, 1 << (i - 1) });
    }
    int h = (1 << high_bit);
    for (int i = 0; i < high_bit; i++) {
        if ((1 << i) & L) {
            e.push_back({ i + 1 , n, h });
            h += (1 << i);
        }
    }
    printf("%d %lu\n", n, e.size());
    for (auto ed: e) {
        printf("%d %d %d\n", ed.u, ed.v, ed.w);
    }
}
