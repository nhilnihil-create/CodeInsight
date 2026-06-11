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
 	int n, z = 1;
	cin >> n;
	for (int i = 2 ; i <= n ; i++) {
		int x = i * i;
		while (x <= n) {
			z = max(z, x);
			x *= i;
		}
	}
	cout << z;
}