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


int main(){
	int n, x, sum = 0;
	cin >> n >> x;
	vector<int> m(n);
	for (int i = 0; i < n; i++){
		cin >> m[i];
		sum += m[i];
	}
	sort(m.begin(), m.end());
	int ans = n;
	x -= sum;
	ans += x/m[0];
	cout << ans << endl;
	return 0;
}
