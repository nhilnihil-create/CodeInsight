    #include <bits/stdc++.h>
    using namespace std;
    #define sd(x) scanf("%d", &x)
    #define slld(x) scanf("%lld", &x)
    #define all(x) x.begin(), x.end()
    #define For(i, s, e) for (ll i = s; i < e; i++)
    #define Forr(i, s, e) for (ll i = s; i > e; i--)
    #define pb push_back
    #define ll long long
    #define mp make_pair
    double dp[300 + 1][300 + 1][300 + 1];

    double sushi(ll a, ll b, ll c, ll n)
    {
        if (a < 0 || b < 0 || c < 0)
            return 0;
        if (a == 0 && b == 0 && c == 0)
            return 0;
        if (dp[a][b][c] >= 0)
            return dp[a][b][c];
        ll sum = a + b + c;
        double xd = n + (a) * (sushi(a - 1, b, c, n)) + (b) * (sushi(a + 1, b - 1, c, n)) + (c) * (sushi(a, b + 1, c - 1, n));
        dp[a][b][c] = xd / sum;
        return dp[a][b][c];
    }
    int main()
    {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        srand(chrono::high_resolution_clock::now().time_since_epoch().count());
        cout << fixed << setprecision(8);
        ll n;
        cin >> n;
        For(i, 0, 300 + 1)
            For(j, 0, 300 + 1)
                For(k, 0, 300 + 1) dp[i][j][k] = -1;
        ll o = 0, t = 0, th = 0;
        For(i, 0, n)
        {
            ll temp;
            cin >> temp;
            if (temp == 1)
                o++;
            if (temp == 3)
                th++;
            if (temp == 2)
                t++;
        }
        cout << sushi(o, t, th, n) << endl;
        return 0;
    }