#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    
    string  n; cin >> n;
    string ans = "No";
    if (n[0] == n[1] && n[1] == n[2]) ans = "Yes";
    if (n[1] == n[2] && n[2] == n[3]) ans = "Yes";
    cout << ans << endl;
    return 0;
}