#include <bits/stdc++.h>

#define rep(l, r) for (int i = (l); i < (r); i++)

typedef long long ll;
 
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    cout << (c <= a + b ? "Yes" : "No") << endl;

    return 0;
}
