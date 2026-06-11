#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <utility>
typedef long long ll;
const int INF = 1e9+1;
const int MOD = 2e9 + 9;
const ll LINF = 1e18;
using namespace std;


int main() {
	string s;
	int ans = INF;
	cin >> s;

	for (int i = 0; i < s.size() - 2; i++) {
		int num = (s[i] - '0') * 100 + (s[i + 1] - '0') * 10 + s[i + 2] - '0';
		if(abs(ans-753)>abs(num-753)){
			ans = num;

		}
	}
	cout << abs(ans-753) << endl;
	return 0;
}