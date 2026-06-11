
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

#define vi vector<int>
#define vii vector<vector<int>>

// int date[12] = {31,28}

void testcase()
{
    string s;
    cin >> s;
    // string a = s.substr(0,2);
    // string b = s.substr(2,4);
    int x = (s[0] - '0') * 10 + s[1] - '0';
    int y = (s[2] - '0') * 10 + s[3] - '0';
    int mm = 0, yy = 0;
    // cout << x << " " << y <<"\n";
    if (x <= 12 && x > 0)
    {
        mm++;
    }
    else
    {
        yy++;
    }
    if (y <= 12 && y > 0)
    {
        mm++;
    }
    else
    {
        yy++;
    }

    if (yy == 2)
    {
        cout << "NA\n";
    }
    else if (mm == 2)
    {
        cout << "AMBIGUOUS\n";
    }
    else
    {
        if (x <= 12 && x > 0)
        {
            cout << "MMYY\n";
        }
        else
        {
            cout << "YYMM\n";
        }
    }
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    testcase();
    return 0;
}