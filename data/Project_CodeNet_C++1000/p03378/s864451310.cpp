#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> road(n+1, 0);
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        road[a]++;
    }
    int to0 = 0, toN = 0;
    for (int cur = x; cur >= 0; cur--) to0 += road[cur];
    for (int cur = x; cur <= n; cur++) toN += road[cur];
    cout << min(to0, toN) << endl;
}