#include<iostream>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<map>
#include<iomanip>
#include<sstream>
#include<vector>
#include<stack>
#include<math.h>
#include<queue>
using namespace std;


int main() {
	const long long int mod = 1000000007;

	map<long long int, long long int>mp;
	//cout << fixed << setprecision(10);
	long long int  n, m, b, c, d, k, h, w,left=1,right=0;
	long long int sc, sr, num2, no[1005][1005] = {};
	char a[1005][1005];
	string s, t;
	cin >> h >> w >> n >> sr >> sc >> s >> t;
	right = w ;
	for (int i = n - 1; i >= 0; i--) {
		if (t[i] == 'R') { left--; }
		if (t[i] == 'L') { right++; }
		left = max(1LL, left);
		right = min(right, w);
		if (s[i] == 'R') { right--; }
		if (s[i] == 'L') { left++; }

		if (left > right || right<1 || left>w) { cout << "NO"; return 0; }
	}
	if (sc < left || right < sc) { cout << "NO"; return 0; }

	left = 1;
	right = h;

	for (int i = n - 1; i >= 0; i--) {
		if (t[i] == 'U') { right++; }
		if (t[i] == 'D') { left--; }
		left = max(1LL, left);
		right = min(right, h);
		if (s[i] == 'U') { left++; }
		if (s[i] == 'D') { right--; }
		
		if (left > right || right<1 || left>h) { cout << "NO"; return 0; }
		
	}
	if (sr < left || right < sr) { cout << "NO"; return 0; }
	cout << "YES";
}