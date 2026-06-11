#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    cout << 0 << endl;
    string s1;
    cin >> s1;
    if (s1 == "Vacant") return 0;

    int l = 0, r = n;
    while (true) {
        int m = (l + r) / 2;
        cout << m << endl;

        string s;
        cin >> s;
        if (s == "Vacant") return 0;

        if (m % 2 == 1 && s != s1 || m % 2 == 0 && s == s1)
            l = m + 1;
        else
            r = m;
    }

    return 0;
}
