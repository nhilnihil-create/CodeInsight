#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    string s;
    cin >> s;
    string sa;
    sa += s[0];
    sa += s[1];
    string sb;
    sb += s[2];
    sb += s[3];
    if ("01" <= sa && sa <= "12" && "01" <= sb && sb <= "12")
    {
        cout << "AMBIGUOUS" << endl;
    }
    else if ("01" <= sa && sa <= "12")
    {
        cout << "MMYY" << endl;
    }
    else if ("01" <= sb && sb <= "12")
    {
        cout << "YYMM" << endl;
    }
    else
    {
        cout << "NA" << endl;
    }
    return 0;
}