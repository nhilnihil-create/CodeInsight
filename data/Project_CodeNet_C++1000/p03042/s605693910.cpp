#include <bits/stdc++.h>
using namespace std;
int main()
{
    string S;
    cin >> S;
    int yy = 10 * (S[0] - '0') + S[1] - '0';
    int mm = 10 * (S[2] - '0') + S[3] - '0';
    if(yy == 0 && mm == 0)
    {
        cout << "NA" << endl;
    }
    else if (yy == 0 && mm > 0 && mm <= 12)
    {
        cout << "YYMM" << endl;
    }
    else if (yy == 0 && mm > 12)
    {
        cout << "NA" << endl;
    }
    else if (yy > 12 && mm == 0)
    {
        cout << "NA" << endl;
    }
    else if (yy <= 12 && mm == 0)
    {
        cout << "MMYY" << endl;
    }
    else if (yy <= 12 && mm <= 12)
    {
        cout << "AMBIGUOUS" << endl;
    }
    else if (yy > 12 && mm <= 12)
    {
        cout << "YYMM" << endl;
    }
    else if (yy <= 12 && mm > 12)
    {
        cout << "MMYY" << endl;
    }
    else
    {
        cout << "NA" << endl;
    }
}
