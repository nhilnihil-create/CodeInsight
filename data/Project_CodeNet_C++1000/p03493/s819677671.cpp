#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int m = 0;
    for (int i = 0; i < s.size(); i++)
        if (s.at(i) == '1')
            m += 1;

    cout << m;
    return 0;
}