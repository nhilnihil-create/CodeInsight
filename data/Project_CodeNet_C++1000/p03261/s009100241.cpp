// https://atcoder.jp/contests/abc109/tasks/abc109_b
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
    int N;
    cin >> N;
    map<string, int> dic;
    vector<string> vec(N);
    REP(i, N)
    {
        cin >> vec[i];
    }
    REP(i, N)
    {
        ++dic[vec[i]];
        if (dic[vec[i]] > 1)
        {
            cout << "No" << endl;
            return 0;
        }
    }
    for (int i = 1; i < N; ++i)
    {
        if (vec[i].front() != vec[i - 1].back())
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
