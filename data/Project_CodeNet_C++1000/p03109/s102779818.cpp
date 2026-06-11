#include <bits/stdc++.h>
#define rep0(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<string, int, int> TU;
typedef tuple<int, int, int> TI;

int main()
{
    string S;
    cin >> S;
    int year = atoi(S.substr(0, 4).c_str());
    int month = atoi(S.substr(5, 7).c_str());
    int day = atoi(S.substr(8, 10).c_str());
    if (year < 2019)
    {
        cout << "Heisei" << endl;
    }
    else if (year == 2019 && month < 4)
    {
        cout << "Heisei" << endl;
    }
    else if (year == 2019 && month == 4 && day <= 30)
    {
        cout << "Heisei" << endl;
    }
    else
    {
        cout << "TBD" << endl;
    }
}
