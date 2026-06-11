#include <bits/stdc++.h>
#define fastio (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using namespace std;

int main() {
    fastio;
    int a, b;
    cin >> a >> b;
    if (a % 2 == 0 || b % 2 == 0)
        cout << "Even" << endl;
    else
        cout << "Odd" << endl;
}