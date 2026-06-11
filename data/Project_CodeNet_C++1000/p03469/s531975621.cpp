#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; ++i)
using namespace std;
int main()
{
    string s;
    cin >> s;
    if (s.at(3) == '7')
    {
        s.at(3) = '8';
    }
    cout << s << endl;
}
