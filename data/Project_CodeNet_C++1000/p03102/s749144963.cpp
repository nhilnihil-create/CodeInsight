#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
int main()
{
    //入力
    int N, M, C;
    cin >> N >> M >> C;

    vector<int> B(M);
    rep(i, M) cin >> B[i];

    vector<vector<int>> A(N, vector<int>(M));
    rep(i, N) rep(j, M) cin >> A[i][j];

    //計算
    int ans = 0;
    rep(i, N)
    {
        int sum = 0;
        for (int j = 0; j < M; ++j)
        {
            sum += A[i][j] * B[j];
        }
        if (sum + C > 0)
        {
            ++ans;
        }
    }
    
    //出力
    cout << ans << endl;
    return 0;
}
