#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int h = 0;
    for (int i = 1; i < b - a; i++) {
        h += i;
    }

    cout << h - a << endl;
    return 0;
}
