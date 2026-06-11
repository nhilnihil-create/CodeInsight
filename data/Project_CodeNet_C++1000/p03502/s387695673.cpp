#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int x = atoi(s.c_str());
    int sum = 0;
    for (int i = 0; i < s.size(); i++)
    {
        sum += (int)s[i] - '0';
    }
    if (x % sum == 0)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
