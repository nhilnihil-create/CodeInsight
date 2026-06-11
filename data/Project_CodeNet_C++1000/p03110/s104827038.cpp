#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    double x, ans = 0;
    string u;
    for (int i = 0; i < n; i++) {
        cin >> x >> u;
        if (u == "JPY") 
            ans += x;
        else
            ans += x * 380000.0;
    }
    cout << ans << endl;
}