#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

typedef long long ll;

#define rep(i, a, n) for (ll i = a; i < (ll)n; ++i)
#define repd(i, n) for (ll i = (n)-1; i >= 0; --i)
#define INF 10e12
#define MOD 1000000000 + 7
#define MAX 51000
#define all(x) (x).begin(), (x).end()
#define MX(x) *max_element(all(x))
#define MN(x) *min_element(all(x))

using namespace std;

int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<pair<string, pair<int, int>>> v(n);
    rep(i, 0, n) cin >> v[i].first >> v[i].second.first, v[i].second.second = i + 1;
    sort(all(v));
    string name;
    rep(i, 0, n)
    {
        int x = i;
        name = v[x].first;
        while (name == v[x].first)
            name = v[x].first, x++;
        for (int j = --x; j >= i; j--)
            cout << v[j].second.second << endl;
        i = x;
    }
}