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
	int n, a, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a;
		ans += a-1;
	}
	cout << ans << endl;
	return 0;
}
