#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 
#include <utility> 
#include <tuple> 
#include <cstdint> 
#include <cstdio> 
#include <map> 
#include <queue> 
#include <set> 
#include <stack> 
#include <deque> 
#include <unordered_map> 
#include <unordered_set> 
#include <bitset> 
#include <cctype> 
#include <cmath>
#include <iomanip>
#include <ctype.h>
#include <numeric>
#include <iterator>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi >;
using vl = vector<ll>;
using vvl = vector<vl >;
using pairi = pair<int, int>;
using pairl = pair<ll, ll>;

#define TR ","
#define TS " "
#define rep(i,N) for(int i=0;i<(int)N;++i)
#define rpt(i,a,b) for(ll i=a;i<(ll)b;++i)
#define all(v) v.begin(), v.end()
#define IO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

ll gcd(ll a, ll b) {
    if (a < b) swap(a, b);
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll x, ll y) {
    return x / gcd(x, y) * y;
}

ll waz = 76543217;

void printVector(const vector<int>& vec) {
    for (int value : vec) {
        cout << value << " ";
    }
    cout << endl;
}

int main()
{
    IO;

    int n; cin >> n;
    vi a(n + 2), b(n+1);
    a[0] = 0;
    a[n + 1] = 0;

    rep(i, n) cin >> a[i + 1];

    int sum = 0;
    rep(i, n+1) sum += abs(a[i] - a[i + 1]);

    rep(i, n) b[i] = abs(a[i + 1] - a[i]) + abs(a[i + 2] - a[i + 1]) - abs(a[i] - a[i + 2]);

    rep(i, n) cout << sum - b[i] << endl;

}