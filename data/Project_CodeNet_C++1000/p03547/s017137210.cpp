#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    
    string x, y; cin >> x >> y;
    string ans;
    if (x == y) ans = "=";
    if (x < y) ans = "<";
    if (y < x) ans = ">";
    cout << ans << endl;
    return 0;
}