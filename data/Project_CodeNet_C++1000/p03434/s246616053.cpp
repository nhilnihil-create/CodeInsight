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
#define PI 3.14159265359
typedef long long ll;
const int MOD = 1e9+7;
const ll LLINF = 7e18;
using namespace std;


int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end(), greater<int>());
	int ans1 = 0, ans2 = 0;
	for (int i = 0; i < n; i++){
		if (i % 2 == 0) ans1 += a[i];
		else ans2 += a[i];
	}
	cout << ans1 - ans2 << endl;
	return 0;
}