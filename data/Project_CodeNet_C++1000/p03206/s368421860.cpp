#include <bits/stdc++.h>
using namespace std;

int main()
{
    int d;
    cin >> d;

    string res = "Christmas";

    if(d == 22)
    {
        cout << res + " Eve Eve Eve" << "\n";
    } 
    if(d == 23)
    {
        cout << res + " Eve Eve" << "\n";
    }
    if(d == 24)
    {
        cout << res + " Eve" << "\n";
    }
    if(d == 25)
    {
        cout << res << "\n";
    }

    return 0;
}