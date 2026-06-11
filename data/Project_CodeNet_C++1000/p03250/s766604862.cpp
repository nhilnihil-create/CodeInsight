#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <limits.h>
 
#define YesNo(b) ((b) ? "Yes" : "No")
#define YESNO(b) ((b) ? "YES" : "NO")

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;



int main()
{
    int A, B, C;
    cin >> A >> B >> C;
    int k2 = max({A ,B, C});
    int ans = k2 * 9 + A + B + C;
    cout << ans << endl;
}