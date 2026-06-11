#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
// Welcome to my source code!

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    if ((abs(a - b) - 1) % 2) cout << "Alice" << endl;
    else cout << "Borys" << endl;
}