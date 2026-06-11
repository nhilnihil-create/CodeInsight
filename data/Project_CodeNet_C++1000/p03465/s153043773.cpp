#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int>a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    bitset<2000001> flag;
    flag[0] = 1;
    int sum = 0;
    for (int i = 0; i < N; ++i) {
        sum += a[i];
        flag |= (flag << a[i]);
    }
    for (int i = sum / 2; i >= 0; --i) {
        if (flag[i]) {
            cout << sum - i << "\n";
            break;
        }
    }
    return 0;
}