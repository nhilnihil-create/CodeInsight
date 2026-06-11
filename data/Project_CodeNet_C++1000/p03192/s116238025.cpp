#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <iomanip>
#include <cassert>
#include <random>
#include <tuple>
#include <cstdint>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using namespace std;
typedef long long ll;

const int INF = 1 << 30;
const int MOD = 1e9 + 7;


int main() {
    string n; cin >> n;
    int ans = 0;
    rep(i, 4) if (n[i] == '2') ans++;
    cout << ans << endl;


    return 0;
}