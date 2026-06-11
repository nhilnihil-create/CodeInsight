#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
#define pb push_back
#define F first
#define S second
const int mod = 1e9+7, A = 1e5+5;

int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    char a[2][3];
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 3; j++)
            cin >> a[i][j];
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 3; j++)
        {
            if (a[i][j] != a[1-i][2-j])
                return cout << "NO", 0;
        }
    cout << "YES";
    return 0;
}