#include<bits/stdc++.h>
#define INF 1e7

using namespace std;
typedef long long int ll;

int main()
{
    int H,W; cin >> H >> W;
    vector<vector<int>>cost(10,vector<int>(10)); for(int i = 0; i < 10; i++) for(int j = 0; j < 10; j++) cin >> cost[i][j];
    vector<vector<int>>A(H,vector<int>(W)); for(int i = 0; i < H; i++) for(int j = 0; j < W; j++) cin >> A[i][j];
    for(int k = 0; k < 10; k++)
    {
        for(int i = 0; i < 10; i++)
        {
            for(int j = 0; j < 10; j++)
            {
                cost[i][j] = min(cost[i][j],cost[i][k] + cost[k][j]);
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < H; i++)
    {
        for(int j = 0; j < W; j++)
        {
            if(A[i][j] == -1 || A[i][j] == 1) continue;
            ans += cost[A[i][j]][1];
        }
    }
    cout << ans << endl;
}