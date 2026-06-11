#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    if(!(a * b % 2))
    {
        cout << "Even" << "\n";
    } else 
    {
        cout << "Odd" << "\n";
    }

    return 0;
}