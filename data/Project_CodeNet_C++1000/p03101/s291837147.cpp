#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main() {
    int h, w, a, b, ans;
    cin >> h >> w >> a >> b;
    ans = (h - a) * (w - b);
    cout << ans << endl;
}