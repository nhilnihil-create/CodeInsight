#include<bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define pii pair<int,int>
#define data pair<int,pii>
#define pos pii

int N, H, W, D, Q;
pos A[100010];
int cost[100010][30];

int dist(int s, int d)
{
    return abs(A[s].first - A[d].first) + abs(A[s].second - A[d].second);
}

signed main()
{
    cin >> H >> W >> D;
    rep(i, H)rep(j, W)
    {
        int a;
        cin >> a;
        A[a] = {i, j};
    }
    N = H * W;

    for(int i = 1; i <= N; i++)
    {
        if(i + D <= N)cost[i][0] = dist(i, i + D);
        else cost[i][0] = 0;
    }
    int tmp = 1;
    for(int i = 1; i < 30; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            if(j + tmp * D <= N)cost[j][i] = cost[j][i - 1] + cost[j + tmp * D][i - 1];
            else cost[j][i] = cost[j][i - 1];
        }
        tmp *= 2;
    }

    cin >> Q;
    while(Q--)
    {
        int l, r;
        cin >> l >> r;
        int num = (r - l) / D;
        int ans = 0, now = l;
        rep(i, 30)
        {
            if(num & (1 << i))
            {
                ans += cost[now][i];
                now += (1 << i) * D;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
