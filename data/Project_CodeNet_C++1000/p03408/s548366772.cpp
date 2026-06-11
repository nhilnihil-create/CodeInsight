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
   	int n, ans = 0;
   	cin >> n;
   	string s[n];
   	for (int i = 0 ; i < n ; i++) cin >> s[i];
   	int m;
   	cin >> m;
   	string t[m];
   	for (int i = 0 ; i < m ; i++) cin >> t[i];
   	for (int i = 0 ; i < n ; i++) {
   		int blue = 0, red = 0;
   		for (int j = 0 ; j < n ; j++) if (s[i] == s[j]) blue++;
		for (int j = 0 ; j < m ; j++) if (s[i] == t[j]) red++;
		ans = max(ans, blue - red);
	}
	cout << ans;
}