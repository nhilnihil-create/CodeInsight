#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

int main()
{
    string s;
    cin >> s;

    int pos = 0;
    if ((s[0] - '0') * 10 + (s[1] - '0') > 0 && (s[0] - '0') * 10 + (s[1] - '0') < 13)
        pos += 1;
    if ((s[2] - '0') * 10 + (s[3] - '0') > 0 && (s[2] - '0') * 10 + (s[3] - '0') < 13)
        pos += 2;
    if (pos == 0)
        cout << "NA" << endl;
    if (pos == 1)
        cout << "MMYY" << endl;
    if (pos == 2)
        cout << "YYMM" << endl;
    if (pos == 3)
        cout << "AMBIGUOUS" << endl;
}