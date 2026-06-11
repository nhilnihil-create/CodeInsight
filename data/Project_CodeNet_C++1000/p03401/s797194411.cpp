#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int a[n + 2];
    a[0] = 0;
    a[n + 1] = 0;
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    int sum = 0;
    for(int i = 0; i <= n; i++)
        sum += abs(a[i] - a[i + 1]);
    for(int i = 1; i <= n; i++)
        cout << sum + abs(a[i - 1] - a[i + 1]) - (abs(a[i - 1] - a[i]) + abs(a[i] - a[i + 1])) << "\n";

    return 0;
}
