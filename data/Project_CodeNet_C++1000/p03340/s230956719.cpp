#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define _ << ' ' <<
using namespace std;
using ll = long long;

int a[200000];
int s[20];

bool ok(int x)
{
    for (int i = 0; i < 20; ++i)
        if ((a[x] & (1 << i)) && s[i])
            return false;
    return true;
}

void add(int x)
{
    for (int i = 0; i < 20; ++i)
        if (a[x] & (1 << i))
            s[i]++;
}

void rem(int x)
{
    for (int i = 0; i < 20; ++i)
        if (a[x] & (1 << i))
            s[i]--;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int p = 0, q = 0;
    ll sol = 0;
    add(p);
    while (q < n)
    {
        while (q + 1 < n && ok(q + 1))
            add(q + 1), q++;
        //cout << p _ q << endl;
        sol += q - p + 1;
        rem(p); p++;
        if (q < p)
        {
            add(p);
            q++;
        }
    }
    cout << sol;
}
