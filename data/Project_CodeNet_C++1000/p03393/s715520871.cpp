// https://atcoder.jp/contests/agc022/tasks/agc022_a
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <stack>
#include <queue>
#include <iomanip>
#include <set>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
    string S;
    cin >> S;
    if (26 == S.size())
    {
        int idx = 25;
        for (int i = 0; i < 25; ++i)
        {
            bool ok = true;
            for (int j = i; j < 25; ++j)
            {
                if (S[j] < S[j + 1]) 
                {
                    ok = false;
                    break;
                }
            }
            if (ok)
            {
                idx = i;
                break;
            }
        }
        if (idx == 0)
        {
            cout << -1 << endl;
            return 0;
        }
        char c = 'z' + 1;
        for (int i = idx; i < 26; ++i)
        {
            if (c > S[i] && S[i] > S[idx - 1]) c = S[i];
        }
        for (int i = 0; i < idx - 1; ++i)
        {
            cout << S[i];
        }
        cout << c << endl;
        return 0;
    }
    vector<int> cnts(26, 0);
    for (int i = 0; i < S.size(); ++i)
    {
        ++cnts[S[i] - 'a'];
    }
    
    int idx = 0;
    for (int i = 0; i < 26; ++i)
    {
        if (cnts[i] == 0)
        {
            idx = i;
            break;
        }
    }
    S.push_back('a' + idx);
    cout << S << endl;
    return 0;
}
