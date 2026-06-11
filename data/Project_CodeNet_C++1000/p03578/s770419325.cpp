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
    vector<int> D(N);
    REP(i, N) cin >> D[i];
    int M;
    cin >> M;
    vector<int> T(M);
    REP(i, M) cin >> T[i];
    unordered_map<int, int> mp;
    REP(i, N)
    {
        ++mp[D[i]];
    }
    REP(i, M)
    {
        if(mp[T[i]] > 0)
        {
            --mp[T[i]];
        }
        else
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
