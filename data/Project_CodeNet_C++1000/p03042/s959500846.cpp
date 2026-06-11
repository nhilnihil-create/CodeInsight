#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
using namespace std;
using ll = long long;

int main()
{
    string S;

    cin >> S;

    string l = S.substr(0, 2);
    string r = S.substr(2, 2);

    bool isYYMM = false;
    bool isMMYY = false;
    // l = YY

    int yy = stoi(l);
    int mm = stoi(r);
    if (0 < mm && mm <= 12)
    {
        isYYMM = true;
    }

    // l = MM
    yy = stoi(r);
    mm = stoi(l);
    if (0 < mm && mm <= 12)
    {
        isMMYY = true;
    }

    if (!isYYMM && !isMMYY)
    {
        cout << "NA" << endl;
    }

    if (isYYMM && !isMMYY)
    {
        cout << "YYMM" << endl;
    }
    if (!isYYMM && isMMYY)
    {
        cout << "MMYY" << endl;
    }
    if (isYYMM && isMMYY)
    {
        cout << "AMBIGUOUS" << endl;
    }

    return 0;
}
