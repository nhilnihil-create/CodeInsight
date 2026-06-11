#include <iostream>
#include <string>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <iomanip>
#include <vector>
#include <functional>
#include <algorithm>
#include <cstdio>
#include <random>
#include <ctime>
#include <cstdlib>
#include <unordered_map>
#include <string.h>
#include <iostream>

using namespace std;
typedef long long ll;
typedef pair<int, int> Pint;
typedef pair<ll, ll> Pll;
#define rep(begin, i, end) for (ll i = begin; i < (ll)(end); i++)
#define all(v) v.begin(), v.end()
const int MOD = 1000000007;

int N, ans;
vector<int> A;

void solve(int n, int mul, vector<int> &A);

int main()
{
    cin >> N;
    A.resize(N);
    rep(0, i, N)
    {
        cin >> A.at(i);
    }
    ans = 0;
    solve(0, 1, A);
    cout << ans << endl;
}

void solve(int n, int mul, vector<int> &A)
{
    if (n == N)
    {
        if (mul % 2 == 0)
        {
            ans++;
        }
        return;
    }
    solve(n + 1, mul * (A.at(n) - 1), A);
    solve(n + 1, mul * A.at(n), A);
    solve(n + 1, mul * (A.at(n) + 1), A);
    return;
}