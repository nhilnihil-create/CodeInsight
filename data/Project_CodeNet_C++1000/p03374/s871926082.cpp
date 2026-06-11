#include <bits/stdc++.h>

using namespace std;

#define int long long

int n, c;
int x[100010], v[100010];
int xr[100010];
int mx[100010], mxr[100010];

main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> c;
    for(int i = 0; i < n; i++) cin >> x[i] >> v[i];
    for(int i = 0; i < n; i++) xr[n-1-i] = c - x[i];
    int sum = 0;
    int pos = 0;
    for(int i = 0; i < n; i++){
        sum = sum - (x[i] - pos) + v[i];
        mx[i] = max((i) ? mx[i-1] : 0, sum);
        pos = x[i];
    }
    sum = 0;
    pos = 0;
    for(int i = 0; i < n; i++){
        sum = sum - (xr[i] - pos) + v[n-1-i];
        mxr[i] = max((i) ? mxr[i-1] : 0, sum);
        pos = xr[i];
    }
    sum = 0;
    pos = 0;
    int an = max(mx[n-1], mxr[n-1]);
    for(int i = 0; i < n - 1; i++){
        sum = sum - 2 * (x[i] - pos) + v[i];
        int tmp = sum + mxr[n-i-2];
        an = max(an, tmp);
        pos = x[i];
    }
    sum = 0;
    pos = 0;
    for(int i = 0; i < n - 1; i++){
        sum = sum - 2 * (xr[i] - pos) + v[n-1-i];
        int tmp = sum + mx[n-i-2];
        an = max(an, tmp);
        pos = xr[i];
    }
    cout << an << endl;
}
