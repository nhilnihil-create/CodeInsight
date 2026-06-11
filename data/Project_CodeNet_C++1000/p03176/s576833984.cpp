#include <bits/stdc++.h>

using namespace std;
const int MAX = 2e5 + 5;
typedef long long ll;

int h[MAX], a[MAX];
ll dp[MAX];

void max_self(ll &a, ll b)
{
    a = max(a, b);
}

int main()
{
    int n;

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> h[i];

    for(int i = 0; i < n; i++)
        cin >> a[i];

    int base = 1;

    while(base <= n)
        base *= 2;

    vector<ll>tree(base * 2);

    for(int flower = 0; flower < n; flower++)
    {
        int nod = base + h[flower];
        ll best = 0;

        while(nod > 1)
        {
            if(nod % 2 == 1)
                max_self(best, tree[nod - 1]);

            nod /= 2;
        }

        dp[h[flower]] = best + a[flower];

        for(int nod = base + h[flower]; nod; nod /= 2)
            max_self(tree[nod], dp[h[flower]]);
       /* for(int j = 0; j < h[i]; j++)
            max_self(dp[h[i]], dp[j] + a[i]);*/
    }

    ll sol = 0;

    for(int i = 0; i < n; i++)
        max_self(sol, dp[h[i]]);

    cout << sol;

    return 0;
}
