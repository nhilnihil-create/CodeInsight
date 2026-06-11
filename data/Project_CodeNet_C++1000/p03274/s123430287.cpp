#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>
#include <math.h>
#include <set>
#include <deque>
#include <queue>
#include <list>
using namespace std;
typedef long long ll;
const int mod = 1000000007;

#define for1(n) for (int i = 0 ; i < n ; i++)
#define for2(n) for (int j = 0 ; j < n ; j++)
#define for3(n) for (int k = 0 ; k < n ; k++)
#define for4(n) for (int l = 0 ; l < n ; l++)
#define forl(n) for (ll i = 0 ; i < n ; i++)

int main() {
    ios::sync_with_stdio(false);
    int n, k;
    ll z = 10000000000ll;
    cin >> n >> k;
    int x[n]; 
    for1(n) cin >> x[i];
    for1(n - k + 1) {
    	ll a;
    	if (x[i] >= 0) a = x[i + k - 1];
    	else if (x[i + k - 1] < 0) a = abs(x[i]);
    	else if (x[i] <= 0 && x[i + k - 1] >= 0) a = min(abs(x[i]), x[i + k - 1]) + abs(x[i] - x[i + k -1]);
    	z = min(z, a);
	}
	if (z == 10000000000ll) cout << 0;
	else cout << z;
}