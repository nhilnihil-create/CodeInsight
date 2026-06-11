#include <bits/stdc++.h>
using namespace std;
//
#define ll long long
#define ull unsigned long long
#define pb push_back
#define mx 100010
#define pi acos(-1)
#define endl '\n'
#define Fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
//
int main()
{
    char ch[3][3];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> ch[i][j];
        }
    }
    cout << ch[0][0] << ch[1][1] << ch[2][2] << endl;
}
