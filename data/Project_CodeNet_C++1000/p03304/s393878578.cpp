#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <tuple>
#include <cstring>
#include <map>
#include <iomanip>
#include <ctime>
#include <complex>
#include <cassert>
#include <climits>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define _ << " " <<
#define all(X) (X).begin(), (X).end()
#define len(X) (X).size()
#define Pii pair<int, int>
#define Pll pair<ll, ll>
#define Tiii tuple<int, int, int>
#define Tlll tuple<ll, ll, ll>

int main() {
    double n, m, d;
    cin >> n >> m >> d;
    cout << fixed << setprecision(16);
    if (d == 0) cout << (m - 1) / n << endl;
    else cout << 2 * (n - d) * (m - 1) / n / n << endl;
}
