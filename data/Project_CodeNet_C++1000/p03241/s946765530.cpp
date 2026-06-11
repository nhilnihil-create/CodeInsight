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
#define for1l(n) for (ll i = 0 ; i < n ; i++)
#define for2l(n) for (ll j = 0 ; j < n ; j++)

int main() {
    ios::sync_with_stdio(false);
    int n, m, z = 0;
    cin >> n >> m;
    for (int i = 1 ; i * i <= m ; i++) {
    	if (m % i == 0) {
    		if (m / i >= n) z = max(z, i);
        	if (i >= n) z = max(z, m / i);
		}
	} 
	cout << z;
}