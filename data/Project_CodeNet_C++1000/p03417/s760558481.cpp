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

ll llmax(ll x, ll y){
	if (x > y) return x;
	return y;
}


int main(){
	ll n, m;
	cin >> n >> m;

	if (n == 1 && m == 1){
		cout << 1 << endl;
	}else if (n == 1 || m == 1){
		cout << llmax(n, m) - 2 << endl;
	}else{
		cout << (n-2)*(m-2) << endl;
	}
	return 0;
}