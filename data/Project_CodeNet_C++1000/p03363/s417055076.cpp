#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <cassert>
#include <fstream>
#include <iomanip>
#include <stack>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

const ll mod = 1e9 + 7;
const ll mmod = 998244353;

vector<ll> dx = {1, -1, 0, 0};
vector<ll> dy = {0, 0, 1, -1};

vector<string> g;
vector<vector<bool>> used;
vector<ll> d;

int main() {
    
    
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    ll n;
    cin >> n;
    vector<ll> c(n);
    map<ll, ll> m;
    
    for (int i = 0; i < n; ++i)
    {
        ll tmp;
        cin >> tmp;
        c[i] += tmp;
        if (i == 0)
        {
            continue;
        }
        c[i] += c[i - 1];
    }
    for (int i = 0; i < n; ++i)
    {
        m[c[i]]++;
    }
    ll ret = m[0];
    for (auto itr = m.begin(); itr != m.end(); ++itr)
    {
        ret += (itr->second * (itr->second - 1)) / 2ll;
    }
    
    cout << ret << endl;
    
    return 0;
}