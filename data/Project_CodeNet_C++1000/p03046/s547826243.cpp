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
const ll LLINF = 1e18;
using namespace std;



int main(){
	int m, k;
	cin >> m >> k;
	if (m == 0){
		if (k == 0) cout << "0 0" << endl;
		else cout << -1 << endl;
	}else if (m == 1){
		if (k == 0) cout << "0 0 1 1" << endl;
		else cout << -1 << endl;
	}else if (pow(2, m) <= k){
		cout << -1 << endl;
	}else{
		for (int i = 0; i < pow(2, m); i++){
			if (i == k) continue;
			cout << i << " ";
		}
		cout << k << " ";
		for (int i = pow(2, m)-1; i >= 0; i--){
			if (i == k) continue;
			cout << i << " ";
		}
		cout << k << endl;
	}
	return 0;
}
