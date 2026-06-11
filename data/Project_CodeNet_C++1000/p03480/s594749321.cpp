#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include<algorithm>
#include<sstream>
#include<iomanip>


using namespace std;

typedef long long ll;

const ll MOD_CONST = 1000000007;
const ll BIG_NUM = 1000000000000000000;



int main() {
	string s;
	cin >> s;
	int n;
	n = s.length();

	
	char lastChar = s[0];
	int ans = n;
	for (int i = 0; i < n;i++) {
		if (s[i] != lastChar) {
			ans = min(ans, max(i, n - i));
			lastChar = s[i];
		}
	}

	
	cout << ans << endl;
	
}
