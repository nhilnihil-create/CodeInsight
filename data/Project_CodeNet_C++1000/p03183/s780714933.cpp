#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <string>
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

struct Block {
    int w, s, v;
    bool operator< (const Block & b) const {
        return w + s > b.w + b.s;
    }
} bt[1010];

long long rucsac[20100];

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d%d%d", &bt[i].w, &bt[i].s, &bt[i].v);

    sort(bt, bt + n);

    for (int i = 0; i < n; i++) {
        for (int j = bt[i].w; j <= 20000; j++) {
            long long & v = rucsac[min(j - bt[i].w, bt[i].s)];
            v = max(v, rucsac[j] + bt[i].v);
        }
    }

    cout << rucsac[0] << '\n';

    return 0;
}
