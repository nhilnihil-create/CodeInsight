#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
ll MOD = 1000000000 + 7;

int main() {
    int n, y;
    cin >> n >> y;
    y /= 1000;
    int sen, go, man;
    bool flag = false;
    for (man = 0; man <= n; man++) {
        for (go = 0; go <= n - man; go++) {
            sen = n - man - go;
            if (sen + 5 * go + man * 10 == y) flag = true;
            if (flag) break;
        }
        if (flag) break;
    }
    if (!flag) sen = go = man = -1;
    cout << man << " " << go << " " << sen << endl;
    return 0;
}