#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    string t = "keyence";
    int a = 0, b = 0;
    for (int i = 0; i < t.size(); i++) if (s[i] == t[i]) a++; else break; reverse(s.begin(), s.end()); reverse(t.begin(), t.end());
    for (int i = 0; i < t.size(); i++) if (s[i] == t[i]) b++; else break; reverse(s.begin(), s.end()); reverse(t.begin(), t.end());
    if (a + b >= 7) cout << "YES";
    else cout << "NO";
}
