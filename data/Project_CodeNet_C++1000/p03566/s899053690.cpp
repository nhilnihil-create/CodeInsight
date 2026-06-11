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
#include<deque>
 
 
using namespace std;
 
typedef long long ll;
 
const ll MOD_CONST = 1000000007;
const ll BIG_NUM = 1000000000000000000;
typedef pair<int, int> pii;
 
 
int main() {
	int n;
	cin >> n;
	vector<int> t(n+1);
	vector<int> sum_t(n + 1);
	for (int i = 0; i < n;i++) {
		cin >> t[i];
		sum_t[i+1] +=sum_t[i] + t[i];
	}
	t[n] = 1;
	vector<int> v(n+1);
	for (int i = 0; i < n;i++) {
		cin >> v[i];
	}
	v[n] = 0;
 
	double vel = 0;
	double ans = 0;
	int i_n = 0;
	//cout << sum_t[n] << endl;
	for (double ti = 1; ti <=2*sum_t[n]; ti++) {
		//cout << ans << endl;
		bool isDecreace = false;
		if (2*(sum_t[i_n] + t[i_n] )< ti) {
			
			i_n++;
			
		}
		for (int i = i_n+1;i <=n;i++) {
			
			
			
			if ((2 * sum_t[i] - ti) <=( vel-1-2 * v[i])) {
				//cout << sum_t[i] << " " << v[i] << endl;
				ans += (2 * vel - 1) / 2.0;
				//cout << ti << " " << (2 * vel - 1) / 2.0 << endl;
				vel--;
				isDecreace = true;
				break;
			}
		}
 
		if (!isDecreace) {
			if (vel == 2 * v[i_n]) {
				ans += vel;
			}
			else {
				ans += (2 * vel + 1) / 2.0;
				//cout << ti << " " << (2 * vel + 1) / 2.0 << endl;
				vel++;
			}
		}
		//cout << ti << " " << vel << endl;
 
	}
	cout << setprecision(10) <<ans/4 << endl;
 
}