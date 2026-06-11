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
   	int n, d, x;
   	cin >> n >> d >> x;
   	int a[n];
   	int b = 0;
   	for (int i = 0 ; i < n ; i++) cin >> a[i];
   	for (int i = 0 ; i < n ; i++) {
   		b += (d - 1) / a[i] + 1; 
	}
	cout << b + x;
}