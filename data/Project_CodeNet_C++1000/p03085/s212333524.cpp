#include <bits/stdc++.h>
using namespace std;

int main()
{
    char input;
    cin >> input;

    if (input == 'A' || input == 'T')
    {
        cout << (char)('A' + 'T' - input) << endl;
    }
    else
    {
        cout << (char)('C' + 'G' - input) << endl;
    }
}