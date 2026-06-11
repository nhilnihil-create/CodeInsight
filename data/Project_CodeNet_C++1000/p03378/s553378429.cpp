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
   	int n, m, x;
   	cin >> n >> m >> x;
   	int a[m + 1], b[n + 1] = {};
   	for (int i = 0 ; i < m ; i++) cin >> a[i], b[a[i]] = 1;
   	int c = 0, d = 0;
   	for (int i = x ; i <= n ; i++) if (b[i]) c++;
   	for (int i = x ; i >= 1 ; i--) if (b[i]) d++;
   	cout << min(c, d);
}