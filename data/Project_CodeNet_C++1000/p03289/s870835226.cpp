// https://atcoder.jp/contests/abc104/tasks/abc104_b
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
    string S;
    cin >> S;
    int N = S.size();
    if ('A' == S[0])
    {
        int cnt = 0, idx = -1;
        for (int i = 2; i < N - 1; ++i)
        {
            if ('C' == S[i])
            {
                ++cnt;
                if (1 == cnt) idx = i;
            }
        }

        if (1 == cnt)
        {
            for (int i = 1; i < N; ++i)
            {
                if (0 == i || idx == i) continue;
                if ('a' > S[i] || 'z' < S[i])
                {
                    cout << "WA" << endl;
                    return 0;
                }
            }
            cout << "AC" << endl;
            return 0;
        }
        else
        {
            cout << "WA" << endl;
            return 0;
        }
        
    }
    cout << "WA" << endl;
    return 0;
}
