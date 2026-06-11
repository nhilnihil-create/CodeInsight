#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cassert>
#include <iostream>
#include <iomanip>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <bitset>

#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define debug(x) cerr << #x << ": " << x << endl

using namespace std;

typedef long long ll;
typedef pair<ll, ll> Pll;
typedef pair<int, int> Pii;

const ll MOD = 1000000007;
const long double EPS = 1e-10;
const int dyx[4][2] = {
    { 0, 1}, {-1, 0}, {0,-1}, {1, 0}
};

int main() {
    std::ios::sync_with_stdio(0); cin.tie(0);
    int n, h, w;
    cin >> n >> h >> w;
    cout << (n-h+1) * (n-w+1) << endl;
}
