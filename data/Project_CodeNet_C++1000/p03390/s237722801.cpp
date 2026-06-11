#include <bits/stdc++.h>

using namespace std;

typedef long long lint;

lint cautBin(lint nr)
{
    if(nr == 1)
        return 1;

    if(nr == 2)
        return 2;

    if(nr == 3)
        return 2;

    if(nr == 4 || nr == 5)
        return 3;

    lint cr = 2;
    lint i = 2;
    lint pas = 1LL << 31;
    while(pas != 0)
    {
        if(cr + (i + pas) * (i + pas + 1) - 2 <= nr)
            i += pas;

        pas >>= 1;
    }

   // cout << nr << " AVEM " << i << "\n";
    lint rez = 2 * i;
    if(cr + i * (i + 1) - 2 + (i + 1) <= nr)
        rez ++;

    return rez;
}

lint getDel(lint a, lint b)
{
    lint prod = 1LL * a * b - 1;

    if(a == 1 || b == 1)
        return 1;

    lint del = 0;
    lint na0 = prod / (a - 1);
    lint na1 = prod / a;
    lint na2 = prod / (a + 1);

    if(na0 != na1 && na1 != na2)
        del = 1;

    lint nb0 = prod / (b - 1);
    lint nb1 = prod / b;
    lint nb2 = prod / (b + 1);

    if(nb0 != nb1 && nb1 != nb2)
        del = 1;

    return del;
}

void solve(lint a, lint b)
{
    if(a == 1 && b == 1)
    {
        cout << 0 << "\n";
        return;
    }

    lint prod = 1LL * a * b - 1;
    lint cat = cautBin(prod);

    lint rez = cat - getDel(a, b);

    cout << rez << "\n";
}

int main()
{
    lint t;
    cin >> t;
    lint a, b;
    while(t > 0)
    {
        cin >> a >> b;

        solve(a, b);

        t --;
    }

    return 0;
}
