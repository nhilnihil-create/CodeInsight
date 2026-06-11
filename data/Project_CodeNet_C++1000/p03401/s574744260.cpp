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
	vector<int> a(n+2);
	vector<int> save(n+1); 
	a[0] = 0;
	a[n+1] = 0;
	for (int i = 1; i <= n; i++) cin >> a[i];

	ll sum = 0;
	for (int i = 0; i <= n; i++){
		sum += abs(a[i] - a[i+1]); 
	}

	for (int i = 0; i < n; i++){
		save[i+1] = abs(a[i] - a[i+1]) + abs(a[i+1] - a[i+2]) - abs(a[i] - a[i+2]);
	}

	for (int i = 1; i <= n; i++){
		cout << sum - save[i] << endl;
	}
}

