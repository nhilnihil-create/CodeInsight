#include <bits/stdc++.h>
#define fastio (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using namespace std;

int main() {
    fastio;
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int left = a + b;
    int right = c + d;
    if (left > right)
        cout << "Left";
    else if (left < right)
        cout << "Right";
    else
        cout << "Balanced";
    cout << endl;
}