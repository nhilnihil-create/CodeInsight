#include <iostream>
#include<cmath>
#include <vector>
#include <map>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>
#include <math.h>
#include <set>
using namespace std;
typedef long long ll;
const int mod = 1000000007;
 
int main() {
    ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	int x = 1;
	for (int i = 0 ; i < n ; i++) {
		if (x < k) x *= 2;
		else x += k;
	}
	cout << x;
}
