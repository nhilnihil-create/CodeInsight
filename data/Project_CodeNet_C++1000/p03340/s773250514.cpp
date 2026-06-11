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

int coun1[21];

int digit(int x){
	int coun = 0;
	if (x == 0) return 1;
	while (x != 1){
		x /= 2;
		coun++;
	}
	return coun + 1;
}

bool is_ok(){
	for (int i = 0; i <= 20; i++){
		if (coun1[i] > 1) return false;
	}
	return true;
}

int main(){
	int n;
	cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	int from = 0;
	ll ans = 0;
	for (int to = 0; to < n; to++){
		for (int i = 0; i < digit(a[to]); i++){
			if (a[to] & (1<<i)) coun1[i]++;
		}
		while (!is_ok()){
			for (int i = 0; i < digit(a[from]); i++){
				if (a[from] & (1<<i)) coun1[i]--;
			}
			from++;
		}
		ans += to - from + 1;
	}
	cout << ans << endl;
	return 0;
}
