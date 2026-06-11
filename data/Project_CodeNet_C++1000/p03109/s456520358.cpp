#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int month = stoi(s.substr(5, 2));

    if (month > 4)
    {
        cout << "TBD" << endl;
    }
    else
    {
        cout << "Heisei" << endl;
    }
}