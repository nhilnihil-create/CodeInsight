#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
ll MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    int h_max = 0;
    for (int i = 0; i < n; i++) {
        h_max = (h_max < h[i]) ? h[i] : h_max;
    }
    int cnt = 0;
    bool zero = true;
    for (int i = 0; i < h_max; i++) {
        for (int j = 0; j < n; j++) {
            if (zero) {
                if (h[j]) {
                    cnt++;
                    h[j]--;
                    zero = false;
                }
            } else {
                if (h[j]) {
                    h[j]--;
                } else {
                    zero = true;
                }
            }
        }
        zero = true;
    }
    cout << cnt << endl;
    return 0;
}