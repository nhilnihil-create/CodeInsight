#include <bits/stdc++.h>
using namespace std;

int n, r;
string s;

int main()
{
    cin >> n >> s;
    for (int i = 0; i < n; i++)
        if (s[i] == 'R') r++;
    puts((r > n/2) ? "Yes" : "No");
    return 0;
}
