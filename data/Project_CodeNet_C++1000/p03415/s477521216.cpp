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
const int MAX = 1e9;
const ll LLMAX = 1e18;
const int INF = numeric_limits<int>::max();
const ll LLINF = numeric_limits<ll>::max();
const double PI = acos(-1.0);

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, a, n) for (int i = a; i <= (n); ++i)

int main() {
    char c1[3]; cin >> c1;
    char c2[3]; cin >> c2;
    char c3[3]; cin >> c3;

    cout << c1[0] << c2[1] << c3[2] << endl;
    return 0;
}
