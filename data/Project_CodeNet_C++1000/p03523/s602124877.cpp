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
    string S; cin >> S;
    string goal = "AKIHABARA";
    // 字数オーバーはNG
    if (S.length() > goal.length())
    {
        cout << "NO\n";
    }
    // 字数一致時は，既に完成しているときのみOK
    else if (S.length() == goal.length())
    {
        cout << (S == "AKIHABARA" ? "YES\n" : "NO\n");
    }
    // 字数が少ないとき
    else
    {
        string added = "";
        int i = 0;
        for (const char ch : goal)
        {
            if (i < S.length())
            {
                if (S[i] == ch)
                {
                    added += ch;
                    ++i;
                }
                else if (ch == 'A')
                {
                    added += 'A';
                }
                else
                {
                    break;
                }
            }
            else
            {
                added += 'A';
            }
        }
        cout << (added == goal ? "YES\n" : "NO\n");
    }
}
