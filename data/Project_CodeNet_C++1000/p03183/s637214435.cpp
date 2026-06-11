#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define F(i,a,b) for(int i=(int)a;i<=(int)b;i++)
#define FD(i,a,b) for(int i=(int)a;i>=(int)b;i--)
#define pii pair<int,int>
#define reset(x,y) memset(x, y,sizeof(x))
#define MIN(x,y) if (x > (y)) x = (y)
#define MAX(x,y) if (x < (y)) x = (y)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define EL putchar('\n');
#define mod 1000000007
#define oo 1000006
typedef pair<int, int> ii;
const int N = 1005;
const int M = 2e4 + 5;
const int inf = 1e15;
int n, dp[N][M], s[N], w[N], v[N];
vector<pair<ii, ii> > vec;
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

void ReadInPut()
{
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        vec.pb({{y + x, x}, {y, z}});
    }
    sort(vec.begin(), vec.end());
}
void Solve()
{
    for(int i = 0; i < vec.size(); i++) {
        s[i + 1] = vec[i].se.fi;
        w[i + 1] = vec[i].fi.se;
        v[i + 1] = vec[i].se.se;
    }
    for(int i=1;i<=n;i++) {
        for(int j=0;j<M;j++)
            dp[i][j] = -inf;
    }
    dp[0][0] = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<M;j++) {
            if(j <= s[i+1])
                dp[i + 1][j + w[i + 1]] = max(dp[i + 1][j + w[i + 1]], dp[i][j] + v[i + 1]);
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
        }
    }
    int ans=0;
    for(int j=0;j<M;j++)ans=max(ans,dp[n][j]);
    cout << ans;
}
main()
{
//    freopen("t.INP","r",stdin);
  //  freopen(".OUT","w",stdout);
    int sotest=1;
    //cin>>sotest;
    for(int i=1;i<=sotest;i++)
    {
        ReadInPut();
        Solve();
    }
}
