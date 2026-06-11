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

int d, n;

bool is_ok(ll x){
	for (int i = 0; i < d; i++){
		if (x % 100 != 0) return false;
		x /= 100;
	}
	if (x % 100 == 0) return false;
	return true;
}

int main(){
	cin >> d >> n;
	int coun = 0;
	for (ll i = 1; ; i++){
		if (is_ok(i)){
			coun++;
		}
		if (coun == n){
			cout << i << endl;
			return 0;
		}
	}
	return 0;
}