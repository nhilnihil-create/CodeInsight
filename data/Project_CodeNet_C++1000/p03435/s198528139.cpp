#define _USE_MATH_DEFINES
#include<iostream>
#include<algorithm>
#include<vector>
#include<stdio.h>
#include<string.h>
#include<cmath>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ll long long
using namespace std;


int main()
{
    int a[3], b[3], c[3][3];
    string ans = "No";
    rep(i, 3) rep(j, 3) cin >> c[i][j];
    rep(i, c[0][0] + 1)
    {
        a[0] = i;
        b[0] = c[0][0] - i;
        rep(j, c[1][1] + 1)
        {
            a[1] = j;
            b[1] = c[1][1] - j;
            rep(k, c[2][2] + 1)
            {
                a[2] = k;
                b[2] = c[2][2] - k;
                if (a[0] + b[1] == c[0][1] &&
                    a[0] + b[2] == c[0][2] &&
                    a[1] + b[0] == c[1][0] &&
                    a[1] + b[2] == c[1][2] &&
                    a[2] + b[0] == c[2][0] &&
                    a[2] + b[1] == c[2][1])
                {
                    ans = "Yes";
                }
            }
        }
    }
    cout << ans << endl;
}
