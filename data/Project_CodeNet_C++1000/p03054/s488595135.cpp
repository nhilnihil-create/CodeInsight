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
#include <unordered_set>
#include <vector>

using namespace std;
using LLONG = long long;
const LLONG MOD = 1000000007;

string S;
vector<set<int>> posLists;

int main()
{
    int H, W, N; cin >> H >> W >> N;
    int sr, sc; cin >> sr >> sc; --sr; --sc;
    vector<char> S(N), T(N);
    for (auto &Si : S) cin >> Si;
    for (auto &Ti : T) cin >> Ti;
    // より条件が厳しくなる後ろ側から後手の"勝確エリア"を計算していく:O(N)
    int aL = 0, aR = W - 1, aU = 0, aD = H - 1;
    for (int i = N - 1; i >= 0; --i)
    {
        // 後手について，なるべく勝確エリアを広げるように行動する
        switch (T[i])
        {
        case 'L':
            aR = min(aR + 1, W - 1);
            break;
        case 'R':
            aL = max(aL - 1, 0);
            break;
        case 'U':
            aD = min(aD + 1, H - 1);
            break;
        case 'D':
            aU = max(aU - 1, 0);
            break;
        }
        // 先手について，なるべく勝確エリアを狭めるように行動する
        switch (S[i])
        {
        case 'L':
            ++aL;
            break;
        case 'R':
            --aR;
            break;
        case 'U':
            ++aU;
            break;
        case 'D':
            --aD;
            break;
        }
        // もし途中で勝確エリアがつぶれることがあれば，必ず先手の勝利
        if (aL > aR || aU > aD)
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    // 初期位置が勝確エリアにあるかどうか判定
    if (aL <= sc && sc <= aR && aU <= sr && sr <= aD)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}
