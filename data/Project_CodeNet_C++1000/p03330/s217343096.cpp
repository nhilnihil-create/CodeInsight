#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>

using namespace std;
using LLONG = long long;
const LLONG MOD = 1000000007;

int main()
{
    int N, C; cin >> N >> C;
    vector<vector<int>> ds(C, vector<int>(C)), cs(N, vector<int>(N));
    for (int i = 0; i < C; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            cin >> ds[i][j];
        }
    }
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            int ci;  cin >> ci; cs[i][j] = ci - 1;
        }
    }
    // 良いグリッドは３色，C<=30なので色の選び方は高々 30C3 < 27000
    // ->前処理で各選び方についてO(1)で違和感の総和を計算できるようにする
    // diffs[i][j][c]:(i,j)をcに変えたときの違和感:O(N^2*C)
    vector<vector<vector<int>>> diffs(N, vector<vector<int>>(N, vector<int>(C)));
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            for (int c = 0; c < C; ++c)
            {
                diffs[i][j][c] = ds[cs[i][j]][c];
            }
        }
    }
    // sums[r][c]:r=(i+j)%3をcで塗ったときの違和感の総和:O(N^2*C)
    vector<vector<int>> sums(3, vector<int>(C, 0));
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            for (int c = 0; c < C; ++c)
            {
                sums[(i + j) % 3][c] += diffs[i][j][c];
            }
        }
    }
    // 全ての色の組み合わせを試す:O(C^3)
    int ans = 1000 * 500 * 500;
    for (int c1 = 0; c1 < C; ++c1)
    {
        for (int c2 = 0; c2 < C; ++c2)
        {
            for (int c3 = 0; c3 < C; ++c3)
            {
                if (c1 != c2 && c2 != c3 && c3 != c1)
                {
                    int sum = sums[0][c1] + sums[1][c2] + sums[2][c3];
                    ans = min(ans, sum);
                }
            }
        }
    }
    cout << ans << endl;
}