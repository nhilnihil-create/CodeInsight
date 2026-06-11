#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define print(x) cout << x << endl;
using namespace std;
typedef long long ll;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int a[3];
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a+3);

    cout << a[2] * 10 + a[0] + a[1] << endl;

    return 0;
}