#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using LLONG = long long;
const LLONG MOD = 1000000007;

int main()
{
    int K; cin >> K;
    vector<LLONG> As(K); for (auto &Ai : As) cin >> Ai;
    // 試合を逆順に辿る：O(K)
    LLONG min = 2, max = 2;
    for (int i = K - 1; i >= 0; --i)
    {
        LLONG Ai = As[i];
        // [min, max]に含まれるAiの倍数のうち，最小値Xiおよび最大値Yiを計算
        LLONG Xi = min % Ai == 0 ? min : (min / Ai + 1) * Ai;
        LLONG Yi = max / Ai * Ai;
        if (Xi > max || Yi < min)
        {
            cout << -1 << endl;
            return 0;
        }
        // 組を作る前の最小人数はXi
        min = Xi;
        // 組を作る前の最大人数はYi＋Ai-1
        max = Yi + Ai - 1;
    }
    cout << min << ' ' << max << endl;
}
