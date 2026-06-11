#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int tak;
    if (m >= n)
        tak = n;
    else
        tak = n - 1;
    
    cout << tak;
}