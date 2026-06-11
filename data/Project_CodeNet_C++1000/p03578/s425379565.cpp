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

int main()
{
    ll N, d;
    cin >> N;
    map<ll, ll> D, T;
    rep(0, i, N)
    {
        cin >> d;
        D[d]++;
    }

    ll M, t;
    cin >> M;
    rep(0, j, M)
    {
        cin >> t;
        T[t]++;
    }
    for (auto m : T)
    {
        if (D[m.first] < m.second)
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}