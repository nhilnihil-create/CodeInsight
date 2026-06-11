#include <bits/stdc++.h>
using namespace std;

int64_t mod = 1000000007;
int64_t large = 9223372036854775807;
double PI = 3.141592653589793;

int main()
{
    int N, M, ans = 0;
    cin >> N >> M;
    vector<vector<bool>> list(N, vector<bool>(M));
    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x;
        for (int j = 0; j < x; j++)
        {
            cin >> y;
            y--;
            list[i][y] = true;
        }
    }
    for (int i = 0; i < M; i++)
    {
        bool z = true;
        for (int j = 0; j < N; j++)
        {
            if (list[j][i] == false)
                z = false;
        }
        if(z)
            ans++;
    }
    cout << ans;
}