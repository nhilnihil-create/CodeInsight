#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

    int a, b, c; cin >> a >> b >> c;
    if (b < a) swap(a, b);
    string ans = "No";
    if (a <= c && c <= b) {
        ans = "Yes";
    }
    cout << ans << endl;
    return 0;
}