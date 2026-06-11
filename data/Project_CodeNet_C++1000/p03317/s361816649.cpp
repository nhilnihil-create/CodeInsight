#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, c = 0, i;
    cin >> n >> k;
    int arr[n+1];

    for(i = 1; i <= n; i++) cin >> arr[i];
    n--;
    k--;
    int res = (n + k - 1) / k;
    cout << res << endl;
}