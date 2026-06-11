#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
#define ll long long
#define ld long double
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define PI 3.14159265358979323846
#define sz(x) ((int)(x).size())
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)

const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
vector<int> f[105];
vector<int> p[105];

int dp[15][2];

int main()
{
    int n;
    cin >> n;
    int temp;
    rep(i,n)
    {
        rep(j,10)
        {
            cin >> temp;
            f[i].push_back(temp);
        }
    }
    rep(i, n)
    {
        rep(j, 11)
        {
            cin >> temp;
            p[i].push_back(temp);
        }
    }
    int ans = -INF;
    for (int i = 1; i < 1024; i++)
    {
        vector<int> counter(n);
        rep(i, n)
        {
            counter[i] = 0;
        }
        for (int j = 0; j < 10; j++)
        {
            if (i & (1 << j))
            {
                for (int k = 0; k < n; k++)
                {
                    if(f[k][j]) counter[k]++;
                }
            }
        }
        int temp=0;
        for (int i = 0; i < n; i++)
        {
            temp += p[i][counter[i]];
        }
        ans = max(temp, ans);
        
    }
    cout << ans << endl;
    
}