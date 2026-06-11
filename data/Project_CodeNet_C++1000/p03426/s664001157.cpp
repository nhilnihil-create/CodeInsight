#include <bits/stdc++.h>
using namespace std;

int64_t MOD = 1000000007;
double PI = 3.141592653589793;

int main()
{
    int H, W, D;
    cin >> H >> W >> D;
    vector<vector<int>> list(H * W, vector<int>(2));  
    int tmp;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cin >> tmp;
            list[tmp - 1][0] = i, list[tmp - 1][1] = j;
        }
    }
    vector<int> length(H * W);
    for (int i = 0; i < H * W; i++)
    {
        if (i < D)
            length[i] = 0;
        else
        {
            tmp = i - D;
            length[i] = length[tmp] + abs(list[tmp][0] - list[i][0]) + abs(list[tmp][1] - list[i][1]);
        }
    }
    int Q, L, R;
    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        cin >> L >> R;
        cout << length[R - 1] - length[L - 1] << endl;
    }
}