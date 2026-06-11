#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define ll int
#define ld long double
using namespace std;
string s, ss;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> s >> ss;
    reverse(s.begin(), s.end());
    if(s == ss)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}
