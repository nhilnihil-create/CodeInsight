// https://atcoder.jp/contests/tenka1-2019-beginner/tasks/tenka1_2019_c
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <set>
#include <unordered_set>
#include <bitset>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define REP(i, n) for(size_t i = 0; i < (n); ++i)

int main()
{
    int N; string S;
    cin >> N >> S;
    int wtot = 0;
    REP(i, N)
    {
        if ('.' == S[i])
        {
            ++wtot;
        }
    }

    int ans = wtot;
    int wnum = 0, bnum = 0;
    REP(i, N)
    {
        if ('.' == S[i])
        {
            ++wnum;
        }
        else
        {
            ++bnum;
        }
        // i 番目より右側にある白石の数を算出
        int rightcnt = wtot - wnum;
        ans = min(ans, bnum + rightcnt);
    }
    cout << ans << endl;
    return 0;
}
