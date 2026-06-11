#include <bits/stdc++.h>

using namespace std;

int main()
{
    string a[3];
    for (int i = 0; i < 3; i++)
        cin >> a[i];
    string b;
    b += a[0].at(0);
    b += a[1].at(1);
    b += a[2].at(2);
    cout << b;
    return 0;
}