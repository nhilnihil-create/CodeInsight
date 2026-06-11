#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define db "Kangaroo"
#define fi first
#define se second
#define endl '\n'
#define int long long
const int INF = 1e18 + 1;
const int mod = 1e9 + 7;
typedef long long ll;
typedef pair<int, int> PII;
typedef pair<PII, int> PII2;
typedef pair<int, PII> PII3;
typedef pair<PII, PII> PII4;

void docfile()
{
    if (ifstream("FORM.inp"))
    {
        freopen("FORM.inp", "r", stdin);
        freopen("FORM.out", "w", stdout);
    }
    else if (ifstream(db".inp"))
    {
        freopen(db".inp", "r", stdin);
        freopen(db".out", "w", stdout);
    }
}


//---------------------------------------------------------------------------
const int N = 16 + 5;
int n, a[N][N], dp[100000], sum[100000];

void input()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
    cin >> a[i][j];
}

int cal(int x)
{
    if(sum[x] != -INF) return sum[x];
    int res = 0;
    vector <int> v;
    for(int i = 0; i < n; i++) if((1<<i)&x) v.push_back(i);
    for(int i = 0; i < v.size(); i++)
    for(int j = i+1; j < v.size(); j++)
    res += a[v[i]][v[j]];
    sum[x] = res;
    return res;
}

void solve()
{
    int m = (1<<n);
    for(int j = 0; j < m; j++) sum[j] = -INF;
    for(int j = 0; j < m; j++)
    {
        for(int k = j; ; k = (j&(k-1)))
        {
            int k2 = j^k;
            dp[j] = max(dp[j], dp[k] + cal(k2));
            if(k == 0) break;
        }
    }
    cout << dp[m-1];
}

main()
{
    docfile();
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    //int test = 1; cin >> test; while(test--) {input(); solve();}
    input(); solve();
}


//-----------------------------------------------------------------------------

/*
int read()
{
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') {if (c == '-') f = -1; c = getchar();}
    while (c >= '0' && c <= '9') {x = x * 10 + c - '0'; c = getchar();}
    return x * f;
}
void write(int x)
{
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}
*/
