#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using namespace std;

int main() {
    fastIO;
    char b;
    cin >> b;
    if (b == 'A')
        cout << 'T';
    else if (b == 'T')
        cout << 'A';
    else if (b == 'G')
        cout << 'C';
    else if (b == 'C')
        cout << 'G';
}