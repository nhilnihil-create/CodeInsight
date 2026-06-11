#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <utility>
#include <iomanip>
#include <cmath>

using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)

int main() {
	string s;

	cin >> s;
	int n = s.size();
	int front_x = 0;
	int back_x = n - 1;
	int ans = 0;

	while(front_x < back_x) {
		if (s.at(front_x) == s.at(back_x)) {
			front_x++;
			back_x--;
			continue;
		}
		if (s.at(front_x) == 'x') {
			ans ++;
			front_x++;
			continue;
		}
		if (s.at(back_x) == 'x') {
			ans ++;
			back_x--;
			continue;
		}
		cout << -1 << endl;
		return 0;


	}
	cout << ans << endl;
	
	return 0;
}