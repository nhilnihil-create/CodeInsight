#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

int n, a, b, c;
int l[10];
int f(int cur, int x, int y, int z) {
    if(cur == n) {
        if(min({x, y, z}) > 0) return abs(x - a) + abs(y - b) + abs(z - c) - 30;
        else return INF;
    }
    int res0 = f(cur + 1, x, y, z);
    int res1 = f(cur + 1, x + l[cur], y, z) + 10;
    int res2 = f(cur + 1, x, y + l[cur], z) + 10;
    int res3 = f(cur + 1, x, y, z + l[cur]) + 10;
    return min({res0, res1, res2, res3});
}

int main() {
    cin >> n >> a >> b >> c;
    for(int i = 0; i < n; i++) cin >> l[i];
    cout << f(0, 0, 0, 0) << endl;
    return 0;
}