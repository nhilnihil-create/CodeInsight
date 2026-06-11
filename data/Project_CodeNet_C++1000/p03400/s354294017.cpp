#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, d, x;
    cin >> n >> d >> x;

    int cnt = x;
    int tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        cnt += (d-1) / tmp + 1;
    }

    cout << cnt << endl;

    return 0;
}
