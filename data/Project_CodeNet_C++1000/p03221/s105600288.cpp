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

#define rep(i, b) for (ll i = 0; i < (ll)b; ++i)
#define INF 10e12
#define MAX 51000
#define all(x) (x).begin(), (x).end()
#define MX(x) *max_element(all(x))
#define MN(x) *min_element(all(x))

using namespace std;

const long long MOD = 1e9 + 7;
string umeru(int x)
{
    string res;
    rep(i, 6 - to_string(x).length())
        res += "0";
    return res + to_string(x);
}
int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll n, m;
    cin >> n >> m;
    vector<int> p(m), y(m);
    rep(i, m) cin >> p[i] >> y[i];
    vector<int> ken(m), shi(m);
    map<int, set<pair<int, int>>> mp;
    rep(i, m)
    {
        ken[i] = p[i];
        mp[p[i]].insert({y[i], i});
    }
    for (auto i : mp)
    {
        int cta = 1;
        for (auto j : i.second)
            shi[j.second] = cta++;
    }
    rep(i, m) cout << umeru(ken[i]) << umeru(shi[i]) << endl;
}