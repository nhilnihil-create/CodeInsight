#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A, B;
    cin >> A >> B;
    string S;
    cin >> S;

    for (int i = 0; i < A + B + 1; i++)
    {
        if (i == A)
        {
            if (S.at(i) != '-')
            {
                cout << "No" << endl;
                return 0;
            }
        }
        else
        {
            if (S.at(i) == '-')
            {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}
