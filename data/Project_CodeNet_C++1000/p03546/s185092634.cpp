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

// 計算量O(v^3)
// 始点、経由店、終点でDPしている
// 負閉路なければいける。負の辺があっても良い
ll dist[10][10];
// 頂点数v, 辺数e
int v= 10;

// 経由店を固定して回す(kが頭にくることに注意)
void warshall_floyd()
{
    for (int k = 0; k < v; k++)
    {
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                if (dist[i][k] != LINF && dist[k][j] != LINF)
                    chmin(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}
// 負閉路あり->false, 負閉路なし->true
bool negative_judge()
{
    // ワーシャルフロイドは所詮DP
    // ループ回しきってdist[i][i]が負になってたら負閉路
    rep(i, v)
    {
        if (dist[i][i] < 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int h,w;cin >> h >> w;

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            if (i == j)
            {
                dist[i][j] = (ll)0;
                continue;
            }
            dist[i][j] = LINF;
        }
    }
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            int c;cin >> c;
            dist[i][j] = c;
        }
    }
    warshall_floyd();
    vector<vector<int> > a(h, vector<int>(w));
    ll sum = 0;
    rep(i,h)
    {
        rep(j,w)
        {
            cin >> a[i][j];
            if(a[i][j] == -1)continue;
            sum += dist[a[i][j]][1];
        }
    }
    cout << sum << endl; 
}