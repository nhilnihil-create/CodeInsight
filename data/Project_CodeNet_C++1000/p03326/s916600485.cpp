#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;
using LLONG = long long;
const LLONG MOD = 1000000007;

int main()
{
    int N, M; cin >> N >> M;
    vector<vector<LLONG>> xyzs(3, vector<LLONG>(N));
    for (int i = 0; i < N; ++i)
    {
        cin >> xyzs[0][i] >> xyzs[1][i] >> xyzs[2][i];
    }
    LLONG ans = 10e-13;
    // x, y, zについて，それぞれ正負どちらの方向で絶対値を最大化するか全探索:O(N)
    for (int bit = 0; bit < (1 << 3); ++bit)
    {
        // bit全探索で符号を変えながら評価値の総和を計算:O(N)
        vector<LLONG> sums(N);
        for (int i = 0; i < N; ++i)
        {
            for (int xyz = 0; xyz < 3; ++xyz)
            {
                if (bit & (1 << xyz))
                {
                    sums[i] += xyzs[xyz][i];
                }
                else
                {
                    sums[i] -= xyzs[xyz][i];
                }
            }
        }
        // 合計の大きい順にM個選ぶ:O(NlogN)
        sort(sums.rbegin(), sums.rend());
        ans = max(ans, accumulate(sums.begin(), sums.begin() + M, 0LL));
    }
    cout << ans << endl;
}
