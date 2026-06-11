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
using namespace std;
typedef long long ll;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0 ; i < n ; i++) cin >> a[i];
    sort(a, a + n);
    int x = 1;
    for (int i = 0 ; i < n - 1 ; i++) {
    	if (a[i + 1] > a[i]) x++; 
	}
	cout << x;
}