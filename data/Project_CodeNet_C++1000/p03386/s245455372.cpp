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
   	int a, b, k;
   	cin >> a >> b >> k;
   	for (int i = a ; i <= b ; i++) {
		if (i <= a + k - 1 || i >= b - k + 1) cout << i << endl; 
	} 
}