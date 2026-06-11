#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int d;
    cin >> d;

    string ans = "Christmas";
    if (d <= 24) ans += " Eve";
    if (d <= 23) ans += " Eve";
    if (d <= 22) ans += " Eve";

    cout << ans << endl;
    return 0;
}
