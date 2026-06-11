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
    int n, z, w;
    cin >> n >> z >> w;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int ans;
    if (n == 1) ans = abs(a[0] - w);
    else ans = max(abs(a[n - 1] - w), abs(a[n - 2] - a[n - 1]));
    cout << ans << endl;

}
