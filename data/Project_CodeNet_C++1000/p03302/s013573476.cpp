#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;

    if((n+m) == 15)
        cout << '+';
    else if((n*m) == 15)
        cout << '*';
    else
        cout << 'x';
}