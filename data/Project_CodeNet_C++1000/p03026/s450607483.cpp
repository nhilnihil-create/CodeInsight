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

const int Cin()
{
    int n;
    cin >> n;
    return n;
}

int main()
{
    int N = Cin();
    vector<vector<int>> adList(N);
    for (int i = 0; i < N - 1; ++i)
    {
        int ai = Cin(), bi = Cin();
        adList[ai - 1].push_back(bi - 1);
        adList[bi - 1].push_back(ai - 1);
    }
    vector<int> cs(N);
    for (auto &ci : cs) ci = Cin();
    sort(cs.rbegin(), cs.rend());
    // これまで考えた部分グラフと連結する辺に
    // これまで使っていない最大の数を入れていく
    vector<bool> hasNotVisited(N, true);
    vector<int> nums(N);
    stack<int> stack;
    stack.push(0);
    int index = 0;
    nums[0] = cs[index];
    hasNotVisited[0] = false;
    ++index;
    int ans = 0;
    // DFSで全ての頂点と接続しながら，大きい数から順に入れていく
    while (!stack.empty())
    {
        int v = stack.top();
        stack.pop();
        for (const int n : adList[v])
        {
            if (hasNotVisited[n])
            {
                stack.push(n);
                hasNotVisited[n] = false;
                nums[n] = cs[index];
                ans += cs[index];
                ++index;
            }
        }
    }
    cout << ans << endl;
    for (int i = 0; i < N; ++i)
    {
        cout << nums[i] << ' ';
    }
    cout << endl;
}
