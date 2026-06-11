#include <bits/stdc++.h>
using namespace std;




























int main () {
    int N, M;
    cin >> N >> M;

    for (int i = N; ; i++) {
        if (M % i == 0) {
            cout << M / i << endl;
            break;
        }
    }
}