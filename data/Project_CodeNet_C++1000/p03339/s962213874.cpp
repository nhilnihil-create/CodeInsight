#include "bits/stdc++.h"

using namespace std;

const int mx = 3e5 + 9;

int e[mx], w[mx];

int main() {
    int n; scanf("%d", &n);
    getchar(); //for clearing newline character
    for (int i = 1; i <= n; i++) {
        char c = getchar();
        if (c == 'W') w[i] = 1;
        else e[i] = 1;
    }

    for (int i = n; i >= 1; i--) e[i] += e[i + 1];
        //e[i] diya ekhon bujhay i theke shuru kore dane koyta E ase
    for (int i = 1; i <= n; i++) w[i] += w[i - 1];
        //w[i] diya ekhon bujhay i theke shuru kore bame koyta W ase

    int ans = n * 2; // maximum ekta number dhore nei

    for (int i = 1; i <= n; i++) {
        //dhori i tomo ta leader
        //so leader er bame jara West dike takaya, tader ke Leader er dike ghurabo
        //mane leader er bamer shob W ke E korbo
        //leader er bame W ase w[i - 1] ta
        int temp = w[i - 1];
        //leader er dane E ase e[i + 1] ta, oderke leader er dike ghurabo
        temp += e[i + 1];
        ans = min(ans, temp);
    }

    printf("%d\n", ans);
}
