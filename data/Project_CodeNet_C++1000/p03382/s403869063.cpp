#include <bits/stdc++.h>

#define fr first
#define sc second
#define mk make_pair
#define pb push_back
#define OK puts("OK");
#define sz(s) (int)s.size()
#define all(s) s.begin(), s.end()

using namespace std;

const int N = 1e5 + 5;

int n, ar[N], ans;

main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        scanf("%d", &ar[i]);

    sort(ar + 1, ar + n + 1);

    ans = 1;

    for (int i = 1; i < n; i++)
    {
        if ( abs(ar[i] - ar[n] / 2) < abs(ar[ans] - ar[n] / 2) )
            ans = i;
    }
    for (int i = 1; i < n; i++)
    {
        if ( abs(ar[i] - (ar[n] + 1) / 2) < abs(ar[ans] - (ar[n] + 1) / 2) )
            ans = i;
    }
    cout << ar[n] << " "  << ar[ans] << endl;
}
