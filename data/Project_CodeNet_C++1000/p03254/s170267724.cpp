#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
#include<cmath>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;


int main()
{
    int n, x, a[100];
    cin >> n >> x;
    rep(i, n) cin >> a[i];
    sort(a, a + n);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        x -= a[i];
        if (x < 0)
        {
            ans = i;
            break;
        }
        else if (x == 0)
        {
            ans = n;
        }
        else
        {
            ans = n - 1;
        }
        
    }
    cout << ans << endl;
}