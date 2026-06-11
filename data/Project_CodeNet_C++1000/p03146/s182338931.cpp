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
	int s;
	int cnt = 0;
	cin >> s;
	vector<int> a(1000001);
	a.at(s) = 1;
	while (1) {
		if (s % 2 == 0) {
			s = s / 2;
			cnt++;
			if (a.at(s) == 1) {
				cout << cnt+1 << endl;
				return 0;
			}
			else {

				a.at(s) = 1;
			}
		}
		else {
			cnt++;
			s = 3 * s + 1;
			if (a.at(s) == 1) {
				cout << cnt+1 << endl;
				return 0;
			}
			else {
				a.at(s) = 1;
			}
		}
		
	}
	
	return 0;
}
