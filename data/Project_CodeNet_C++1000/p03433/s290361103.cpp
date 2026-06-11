#include <bits/stdc++.h>
using namespace std;

int main()
{
    int prime, yen_1;
    cin >> prime >> yen_1;
    int yen_2 = prime % 500;
    if (yen_1 - yen_2 >= 0)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}