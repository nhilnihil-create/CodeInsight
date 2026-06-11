#include <bits/stdc++.h>
using namespace std;

int func_sums(int x) {
    int res = 0;
    while (x != 0) {
        res += x % 10;
        x /= 10;
    }

    return res;
}

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    int sum = 0, tmp;
    for (int i = 1; i <= n; i++) {
        tmp = func_sums(i);
        if (a <= tmp && tmp <= b) sum += i;
    }

    cout << sum << endl;

    return 0;
}
