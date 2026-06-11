#include <bits/stdc++.h>

using namespace std;

int N, x;
int a[100];

void solve() {
    int num = 0, tmp = x;
    sort(a, a + N);
    for (int i = 0; i < N; ++i) {
        if (x >= a[i]) {
            x -= a[i];
            num++;
        } else {
            break;
        }
    }
    if (num == N && x) --num;
    cout << num << endl;
}

int main() {
    cin >> N >> x;
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    solve();
    return 0;
}