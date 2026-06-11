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
    int n, z = 0;
    string s;
    cin >> n >> s;
    for (int i = 1 ; i < n ; i++) {
    	string a = s.substr(0, i), b = s.substr(i, n - i);
    	int c[26] = {}, d[26] = {}, e = 0;
    	for (int j = 0 ; j < i ; j++) c[a[j] - 'a'] = 1;
        for (int j = 0 ; j < n - i ; j++) d[b[j] - 'a'] = 1;
        for (int j = 0 ; j < 26 ; j++) if (c[j] && d[j]) e++;
        z = max(z, e);
	}
	cout << z;
}