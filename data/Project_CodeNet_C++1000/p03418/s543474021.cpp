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
	int n, k;
	cin >> n >> k;
	ll ans = 0;
	for (int b = k+1; b <= n; b++){
		int num = n / b;
		if (k == 0) ans += (b - k)*num - 1;
		else ans += (b - k)*num;
		ans += max(0, n - (b*num+k)+1);
	}
	cout << ans << endl;
	return 0;
}