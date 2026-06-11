#include <bits/stdc++.h>

#define rep(l, r) for (int i = (l); i < (r); i++)

typedef long long ll;
 
using namespace std;

int main() {
    int a, b, x;
    cin >> a >> b >> x;

    cout << (x < a ? "NO" : x <= (a + b) ? "YES" : "NO") << endl;

    return 0;
}
