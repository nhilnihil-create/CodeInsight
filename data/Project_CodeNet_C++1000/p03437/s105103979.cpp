#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll x, y;
    cin >> x >> y;
    if(y == 1) puts("-1");
    else if(x%2 == 0 && y == 2) puts("-1");
    else if(x % y == 0) puts("-1");
    else cout << x * (y - 1) << endl;
}
