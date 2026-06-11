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
    ll n, c = 0;
    cin >> n;
    vector<int> a;
    ll b = 2;
    while (n) {
    	if (n % b) {
    		a.push_back(1);
    		if (c % 2 != 0) n += b / 2;
    		else n -= b / 2;
		}
    	else a.push_back(0);
    	b *= 2;
    	c++;
	}
	reverse(a.begin(), a.end());
	if (a.size() == 0) cout << 0; 
    for (int i = 0 ; i < a.size() ; i++) cout << a[i];
}
/*
*/
