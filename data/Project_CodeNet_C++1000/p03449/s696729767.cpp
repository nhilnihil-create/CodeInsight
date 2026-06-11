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
	int n;
	cin >> n;
	vector<int> a1(n+1), a2(n+1);
	for (int i = 1; i <= n; i++){
		cin >> a1[i];
	}
	for (int i = 1; i <= n; i++){
		cin >> a2[i];
	}
	vector<int> sum1(n+1), sum2(n+1);
	sum1[0] = 0;
	sum2[0] = 0;
	for (int i = 1; i <= n; i++){
		sum1[i] += sum1[i-1] + a1[i];
		sum2[i] += sum2[i-1] + a2[i]; 
	}
	int ans = 0;
	for (int i = 1; i <= n; i++){
		ans = max(sum1[i] + sum2[n] - sum2[i-1], ans);
	}

	cout << ans << endl;
	return 0;
}