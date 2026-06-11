#include <bits/stdc++.h>

#define rep(l, r) for (int i = (l); i < (r); i++)

typedef long long ll;
 
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int l = a + b;
    int r = c + d;

    if (l == r) {
        cout << "Balanced";
    } else if (l < r) {
        cout << "Right";
    } else {
        cout << "Left";
    }
    cout << endl;

    return 0;
}
