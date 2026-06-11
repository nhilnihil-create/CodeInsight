#include <bits/stdc++.h>

using namespace std;

int n, a, b;

int ap[15];
int stk[15];

int dp[15][2];

void out(int nr)
{
    cout << "-1\n";

    //assert(nr == 0);
    exit(0);
}


void verif()
{
    int i, j;
    for(i = 1; i <= n; i ++)
        dp[i][0] = dp[i][1] = 0;

    int na = 0;
    int nb = 0;
    for(i = 1; i <= n; i ++)
    {
        dp[i][0] = 1;

        for(j = 1; j < i; j ++)
        {
            if(stk[j] < stk[i])
                dp[i][0] = max(dp[i][0], dp[j][0] + 1);
        }

        na = max(na, dp[i][0]);
    }

    for(i = 1; i <= n; i ++)
    {
        dp[i][1] = 1;
        for(j = 1; j < i; j ++)
        {
            if(stk[j] > stk[i])
                dp[i][1] = max(dp[i][1], dp[j][1] + 1);
        }

        nb = max(nb, dp[i][1]);
    }

//    cout << na << " " << nb << "\n";

    if(a != na || b != nb)
        return;

    cout << "DA\n";

    for(i = 1; i <= n; i ++)
        cout << stk[i] << " ";
    cout << "\n";

    exit(0);
}

void bkt(int k)
{
    if(k == n + 1)
    {
        verif();

        return;
    }

    int i;
    for(i = 1; i <= n; i ++)
    {
        if(ap[i] == 0)
        {
            ap[i] = 1;
            stk[k] = i;
            bkt(k + 1);
            ap[i] = 0;
        }
    }
}

void c1()
{
    int i;
    int grup = 1;
    for(i = 1; i <= n; i ++)
    {
        int mn = (n - b) / i + 1;
        int mx = n - b - i + 1 + 1;

      //  cout << i << " " << mn << " " << mx << " " << a << "\n";
        if(a >= mn && a <= mx)
        {
            grup = i;

            break;
        }
    }

    //cout << grup << "\n";

    if(grup > b)
    {
        out(1);
    }

    int bs = 0;
    for(i = 0; i * b + b <= n; i ++)
    {
        if(i + 1 <= a && a <= n - b - i * b + i + 1)
            bs = i;
    }

    int rest = 0;
    if(bs + 1 + (n - b - bs * b) > a)
        rest = bs + 1 + (n - b - bs * b) - a;

    //cout << bs << " " << rest << "\n";

    if(rest > 0)
    if(n - b - bs * b <= rest)
        out(0);

    int nr = 0;
    int catul = rest + (rest > 0);
    for(i = 1; i <= n - b - bs * b - (catul); i ++)
    {
        cout << i << " ";
        nr = i;
    }

    int ult = nr;
    int j;
    if(rest > 0)
    for(j = nr + rest + 1; j >= nr + 1; j --)
        cout << j << " ", ult = max(ult, j);

    for(i = 1; i <= bs; i ++)
    {
        int ant = ult;
        for(j = ult + b; j >= ult + 1; j --)
            cout << j << " ", ant = max(ant, j);

        ult = ant;
    }

    for(i = n; i >= n - b + 1; i --)
        cout << i << " ";
}

void c3()
{
    int i;
    for(i = 1; i < a; i ++)
        cout << i << " ";

    for(i = a; i <= n; i ++)
        cout << n - (i - a) << " ";
    cout << "\n";
}

void solve()
{
    if(a + b <= n)
        c1();

    if(a + b == n + 1)
        c3();
}

int main()
{

    cin >> n >> a >> b;

    if(a == 1 || b == 1)
    {
        if(a + b != n + 1)
            out(1);
    }

    if(a + b > n + 1)
        out(1);

    solve();

   // bkt(1);

    return 0;
}
