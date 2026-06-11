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
    int n, z = 0, b = 0;
    cin >> n;
    int a, c = 0;
    for (int i = 0 ; i < n ; i++) {
    	cin >> a;
    	int b = 1;
    	while (b) {
    		if (a % 2 == 0) {
    			c++;
    			a /= 2;
			}
			else break;
		}
	}
	cout << c;
}