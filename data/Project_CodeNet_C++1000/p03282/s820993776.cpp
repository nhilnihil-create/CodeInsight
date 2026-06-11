#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    long long k, n;
    cin >> s >> k;
    n = s.length();
    for (int i = 0; i < min(k, n); i++)
    {
        if (s[i] != '1')
        {
            cout << s[i];
            return 0;
        }
    }
    cout << '1';
}