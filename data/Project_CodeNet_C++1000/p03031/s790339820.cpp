#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <deque>
#include <stack>
#include <map>
const int MOD = 1e9+7;
#define PI 3.14159265359
typedef long long ll;
using namespace std;

int n, m;
int k[11];
bool sw[11][11];
int p[11];

int test(vector<int> &vec){
	for (int i = 1; i <= m; i++){
		int coun = 0;
		for (int j = 1; j <= n; j++){
			if (sw[i][j] && vec[j] == 1){
				coun++;
			}
		}
		if (coun % 2 != p[i]) return 0;
	}
	return 1;
}

int main(){
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++){
			int x;
			cin >> x;
			sw[i][x] = true;
		}
	}
	for (int i = 1; i <= m; i++) cin >> p[i];

	int ans = 0;
	for (int i = 0; i < (1<<n); i++){
		vector<int> vec;
		vec.push_back(0);
		for (int j = 0; j < n; j++){
			if (i & (1<<j)) vec.push_back(1);
			else vec.push_back(0);
		}
		ans += test(vec);
	}
	cout << ans << endl;
	return 0;
}