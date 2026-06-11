#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main() {
    int a, b, c, d, ans;
    cin >> a >> b >> c >> d;
    ans = ((a < b)? a : b) + ((c < d)? c : d);
    cout << ans << endl;
}