#include <bits/stdc++.h>
using namespace std;
int main()
{
    string S;
    cin >> S;
    int yy = 10 * (S[0] - '0') + S[1] - '0';
    int mm = 10 * (S[2] - '0') + S[3] - '0';
    if (yy >= 1 && yy <= 12)
    {
        if (mm >= 1 && mm <= 12)
        {
            cout << "AMBIGUOUS" << endl;
        }
        else
        {
            cout << "MMYY" << endl;
        }
    }
    else if (mm >= 1 && mm <= 12)
    {
        cout << "YYMM" << endl;
    }
    else
    {
        cout << "NA" << endl;
    }
}
