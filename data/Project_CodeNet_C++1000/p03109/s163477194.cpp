#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ss second
#define ff first
#define all(a) a.begin(), a.end()
#define All(a) a.rbegin(), a.rend()
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.precision(10), cout << fixed
int main() {
    ios;
    string s;
    cin >> s;
    int m = 0, d = 0;
    for (int i = 5, k = 0; i < s.size(); ++i) {
        if (s[i] == '/') {
            k = 1;
            continue;
        }
        if (!k)
            m = m * 10 + s[i] - '0';
        else
            d = d * 10 + s[i] - '0';
    }
    if (m <= 4) {
        if (m == 4 && d <= 30)
            cout << "Heisei\n";
        else if (m < 4)
            cout << "Heisei\n";
        else
            cout << "TBD\n";
    } else
        cout << "TBD\n";
    return 0;
}