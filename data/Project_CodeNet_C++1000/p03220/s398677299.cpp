// template
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
    int N, T, A;
    cin >> N >> T >> A;
    vector<int> H(N);
    REP(i, N) cin >> H[i];
    int ans = -1;
    double mval = 1000.0;
    REP(i, N)
    {
        double diff = abs(A - (T - H[i] * 0.006));
        if (mval > diff)
        {
            ans = i + 1;
            mval = diff;
        }
    }
    cout << ans << endl;
    return 0;
}
