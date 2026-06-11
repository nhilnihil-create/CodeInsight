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
using namespace std;
typedef long long ll;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0 ; i < n ; i++) cin >> a[i];
    bool b = 1;
    int c = 0;
    while (b) {
    	for (int i = 0 ; i < n ; i++) if (a[i] % 2 == 1) b = 0;
		if (b) {
			for (int i = 0 ; i < n ; i++) a[i] /= 2;
			c++;
		}
	}
    cout << c;
}