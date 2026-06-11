#include <iostream>
#include <bitset>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <regex>
#include <iomanip>
#include <climits>
using namespace std;
using ll = long long int;
using dd = long double;
const ll MOD = 1e9 + 7;

ll gcd(ll a, ll b)
{
    if (a % b == 0)
    {
        return b;
    }
    return gcd(b, a % b);
}

int main()
{
    string S;
    cin >> S;

    bool YYMM = false, MMYY = false;
    {
        bool year = false, month = false;
        for (ll i = 0; i < 100; i++)
        {
            ostringstream s;
            s << setfill('0') << setw(2) << i;
            if (s.str() == S.substr(0, 2))
            {
                year = true;
            }
        }
        for (ll i = 1; i <= 12; i++)
        {
            ostringstream s;
            s << setfill('0') << setw(2) << i;
            if (s.str() == S.substr(2, 2))
            {
                month = true;
            }
        }
        YYMM = year && month;
    }
    {
        bool year = false, month = false;
        for (ll i = 0; i < 100; i++)
        {
            ostringstream s;
            s << setfill('0') << setw(2) << i;
            if (s.str() == S.substr(2, 2))
            {
                year = true;
            }
        }
        for (ll i = 1; i <= 12; i++)
        {
            ostringstream s;
            s << setfill('0') << setw(2) << i;
            if (s.str() == S.substr(0, 2))
            {
                month = true;
            }
        }
        MMYY = year && month;
    }

    if (YYMM && MMYY)
    {
        cout << "AMBIGUOUS" << endl;
    }
    else if (YYMM)
    {
        cout << "YYMM" << endl;
    }
    else if (MMYY)
    {
        cout << "MMYY" << endl;
    }
    else
    {
        cout << "NA" << endl;
    }
}