#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    int n = s.size(), t = n;
    for (int i = 1; i < n; i++)
        if (s[i] != s[i - 1])
            t = min(max(i, n - i), t);
    cout << t;
}