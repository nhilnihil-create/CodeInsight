#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    string s;
    cin >> s;
    // string y = s.substr(0, 4);
    // string m = s.substr(5, 2);
    // string d = s.substr(8, 2);
    // s = y + m + d;
    if (s > "2019/04/30")
        cout << "TBD" << endl;
    else
        cout << "Heisei" << endl;
    return 0;
}