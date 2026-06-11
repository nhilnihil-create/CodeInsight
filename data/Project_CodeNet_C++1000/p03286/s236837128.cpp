#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cassert>
#include <cstdint>
#include <numeric>
#include <bitset>
#include <functional>

using namespace std;

using ll =  long long;
using Pll = pair<ll, ll>;
using Pii = pair<int, int>;

constexpr ll MOD = 1000000007;
constexpr long double EPS = 1e-10;
constexpr int dyx[4][2] = {
    { 0, 1}, {-1, 0}, {0,-1}, {1, 0}
};

int main() {
    ll n;
    cin >> n;
    vector<int> v;
    while(n) {
        v.push_back(n&1);
        n -= n&1;
        n /= -2;
    }
    for(int i=v.size()-1;i>=0;--i) {
        cout << v[i];
    }
    if(v.size() == 0) cout << "0";
    cout << endl;
}