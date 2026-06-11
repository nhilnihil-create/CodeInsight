// https://atcoder.jp/contests/abc079/tasks/abc079_b
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
    vector<ll> lucas(N+1);
    lucas[0] = 2;
    lucas[1] = 1;
    for (int i = 2; i < N + 1; ++i)
    {
        lucas[i] = lucas[i - 1] + lucas[i - 2];
    }
    cout << lucas[N] << endl;
    return 0;
}
