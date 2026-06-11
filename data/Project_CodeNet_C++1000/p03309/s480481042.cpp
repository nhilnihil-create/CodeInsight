#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <deque>
#include <map>
const int MOD = 1e9+7;
typedef long long ll;
using namespace std;



int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 1; i <= n; i++){
		cin >> a[i-1];
		a[i-1] -= i;
	}
	sort(a.begin(), a.end());
	ll mid = a[(n-1)/2], ans = 0; 
	for (int i = 0; i < n; i++){
		ans += abs(a[i] - mid);
	}
	cout << ans << endl;
	return 0;
}
