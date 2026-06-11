#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

map<int, int> m;
int search(int n) {
    int cnt = 0;
    for (auto tmp : m) {
        if (tmp.second >= n) ++cnt;
    }
    return cnt;
}

int main() {
    int N;
    cin >> N;

    // n!の素因数分解
    for (int i = 1; i <= N; i++) {
        int t = i;

        for (int j = 2; j <= sqrt(t); j++) {
            if (t % j != 0) continue;

            int ext = 0;
            while (t % j == 0) {
                ++ext;
                t /= j;
            }
            m[j] += ext;
        }
        if (t != 1) m[t]++;
    }

    int res = search(74) + search(24) * (search(2) - 1) + search(14) * (search(4) - 1) + search(4) * (search(4) - 1) * (search(2) - 2) / 2;

    cout << res << endl;
}