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
    const int i_max = 200000;
    int n, k;
    vector<int> a(i_max, 0);
    cin >> n >> k;
    rep(i, n)
    {
        int tmp;
        cin >> tmp;
        a[tmp]++;
    }
    sort(a.begin(), a.end());
    int z_end;
    rep(i, i_max)
    {
        if (a[i] != 0)
        {
            z_end = i;
            break;
        }
    }
    int n_size = i_max - z_end;
    int ans = 0;
    rep(i, n_size - k)
    {
        ans += a[z_end + i];
    }
    cout << ans << endl;
}
