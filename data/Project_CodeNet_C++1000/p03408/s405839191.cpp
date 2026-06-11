#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, sum = 0;
    cin >> n;
    string s[n];
    for (int i = 0; i < n; i++) cin >> s[i];
    cin >> m;
    string t[m];
    for (int i = 0; i < m; i++) cin >> t[i];
    for (int i = 0; i < n; i++)
    {
        int r = 0;
        for (int j = 0; j < n; j++)
            if (s[i] == s[j]) r++;
        for (int j = 0; j < m; j++)
            if (s[i] == t[j]) r--;
        sum = max(sum, r);
    }
    cout << sum;
}