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
	int n;
	cin >> n;
	int a[n + 2];
	a[0] = 0;
    a[n + 1] = 0;
	for (int i = 1 ; i <= n ; i++) cin >> a[i];
	int b = 0;
	for (int i = 1 ; i <= n + 1 ; i++) b += abs(a[i] - a[i - 1]);
	for (int i = 1 ; i <= n ; i++) {
        int ans = b;
        ans = ans - abs (a[i] - a[i - 1]) - abs (a[i] - a[i + 1]) + abs (a[i - 1] - a[i + 1]);
        cout << ans << endl;
    }
}
/*
3 + 6 + 2 + 1
3
step 1:- a[i] - a[i - 1]
6 + 2 + 1
step 2:- a[i + 1] - a[i]
6 + 1
step 3:+ a[i + 1] - a[i - 1]
5 + 6 + 1
*/