#include <bits/stdc++.h>
using namespace std;
int main()
{
    string S;
    cin >> S;
    int mm = (S[5] - '0') * 10 + (S[6] - '0');
    int dd = (S[8] - '0') * 10 + (S[9] - '0');
    if (mm < 4)
    {
        cout << "Heisei" << endl;
    }
    else if (mm == 4 && dd <= 30)
    {
        cout << "Heisei" << endl;
    }
    else
    {
        cout << "TBD" << endl;
    }
}