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
    if (s[0] != 'A') cout << "WA", exit(0);
    int t = 0;
    for (int i = 2; i + 1 < s.size(); i++) if (s[i] == 'C') t++;
    int tr = 0;
    for (int i = 1; i < s.size(); i++) if (s[i] >= 'A' && s[i] <= 'Z') tr++;
    if (t == 1 && tr == 1) cout << "AC";
    else cout << "WA";
}
