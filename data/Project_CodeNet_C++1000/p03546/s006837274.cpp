#include <bits/stdc++.h>
#define INF 1e9
using namespace std;
using ll = long long;


int main(void)
{
    int H, W;
    cin >> H >> W;
    vector<vector<int>> c(10, vector<int>(10));
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cin >> c[i][j];
        }
    }
    vector<vector<int>> A(H, vector<int>(W));

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cin >> A[i][j];
        }
    }
    
    for (int k = 0; k < 10; k++)
    {
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if(c[i][j] > c[i][k] + c[k][j]){
                    c[i][j] = c[i][k] + c[k][j];
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if(A[i][j] == -1) continue;
            ans += c[A[i][j]][1];
        }
    }
    
    cout << ans << endl;
    
    return 0;
}
