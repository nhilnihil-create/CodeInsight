#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    
    int a, b; cin >> a >> b;
    int ans;
    if ((a + b) % 2 == 1) ans = (a + b) / 2 + 1;
    else ans = (a + b) / 2;
    cout << ans << endl;
    return 0;
}