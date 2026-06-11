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

int main() {
    ios::sync_with_stdio(false);
    ll n, b = 0, z = 0;
    cin >> n;
    ll a[n + 1];
    for (ll i = 1 ; i <= n ; i++) cin >> a[i], a[i] -= i;
    sort(a + 1, a + n + 1);
    if (n % 2) b = a[n / 2 + 1]; 
    else b = a[n / 2];
    for (ll i = 1 ; i <= n ; i++) z += abs(a[i] - b); 
	cout << z;
}