#include <bits/stdc++.h>
using namespace std;
int main() {
    string s, t;
    cin >> s >> t;
    int m = s.length(), n = t.length();
    int lcs[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0) lcs[i][j] = 0;
            else if (s[i - 1] == t[j - 1]) lcs[i][j] = lcs[i][j] = lcs[i - 1][j - 1] + 1;
            else lcs[i][j] = max(lcs[i][j - 1], lcs[i - 1][j]);
        }
    }
    int i = m, j = n;
    string e = "";
    while (i > 0 && j > 0)
    {
        if (s[i - 1] == t[j - 1])
        {
            e += s[i - 1];
            i--;
            j--;
        }
        else
        {
            if (lcs[i][j - 1] > lcs[i - 1][j]) j--;
            else i--;
        }
    }
    reverse(e.begin(), e.end());
    cout << e;
}