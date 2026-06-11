#include <bits/stdc++.h>
using namespace std;
int main()
{
    int sum = 700;
    string s;
    cin >> s;
    for (int i = 0; i < 3; i++)
    {
        if (s.at(i) == 'o')
        {
            sum += 100;
        }
    }
    cout << sum << endl;
}