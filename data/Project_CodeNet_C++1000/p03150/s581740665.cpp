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
    string s;
    cin >> s;
    int N = s.size();
    rep(0, i, 8)
    {
        string sub1 = s.substr(0, i);
        string sub2 = s.substr(N + i - 7, 7 - i);
        if (sub1 + sub2 == "keyence")
        {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}