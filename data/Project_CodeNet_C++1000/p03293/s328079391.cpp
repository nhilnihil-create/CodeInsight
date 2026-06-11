// https://atcoder.jp/contests/abc103/tasks/abc103_b
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
    string S, T;
    cin >> S >> T;
    size_t N = S.size();
    REP(i, N)
    {
        bool ok = true;
        REP(j, N)
        {
            size_t idx = (i + j) % N;
            if (S[idx] != T[j])
            {
                ok = false;
                break;
            }
        }
        if (ok)
        {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
