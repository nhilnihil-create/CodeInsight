#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<map>
#include<set>
#include<iomanip>

using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const int INF = numeric_limits<int>::max();
const ll LLINF = numeric_limits<ll>::max();
const double PI = acos(-1.0);

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, a, n) for (int i = a; i <= (n); ++i)

int main() {
    int D; cin >> D;
    map<int, string> mp;
    mp[25] = "Christmas";
    mp[24] = "Christmas Eve";
    mp[23] = "Christmas Eve Eve";
    mp[22] = "Christmas Eve Eve Eve";

    cout << mp[D] << endl;
    return 0;
}
