#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    long long l1 = 2, l2 = 1, tmp;
    if (N == 1) {
        cout << l2 << endl;
        return 0;
    }
    for (int i = 1; i < N; i++) {
        tmp = l2;
        l2 += l1;
        l1 = tmp;
    }
    cout << l2 << endl;
}