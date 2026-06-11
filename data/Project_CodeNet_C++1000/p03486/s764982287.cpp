#include <bits/stdc++.h>
using ll = unsigned long long int;
using namespace std;
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)

int main() {
    fastIO;
    string s;
    cin >> s;
    sort(s.begin(), s.end());

    string t;
    cin >> t;
    sort(t.begin(), t.end());
    reverse(t.begin(), t.end());

    if (s < t)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}