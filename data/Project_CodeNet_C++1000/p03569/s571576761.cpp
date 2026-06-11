// https://atcoder.jp/contests/code-festival-2017-qualc/tasks/code_festival_2017_qualc_c
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
    string s;
    cin >> s;
    deque<char> sdq;
    REP(i, s.size())
    {
        sdq.push_back(s[i]);
    }
    int ans = 0;
    // s が最終的に回文になる場合、
    // 先頭文字と末尾文字を削除しても回文となるので、
    // s の先頭文字と末尾文字に着目し、削除と挿入を行う
    while (!sdq.empty())
    {
        if (sdq.front() == sdq.back())
        {
            if (sdq.size() == 1) break;
            sdq.pop_front();
            sdq.pop_back();
        }
        else if (sdq.front() == 'x')
        {
            sdq.push_back('x');
            ++ans;
        }
        else if (sdq.back() == 'x')
        {
            sdq.push_front('x');
            ++ans;
        }
        else
        {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << ans << endl;
    return 0;
}
