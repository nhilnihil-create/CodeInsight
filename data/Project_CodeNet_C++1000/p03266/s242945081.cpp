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

ll hoge(ll x){
	if (x >= 3) return x*x*x;
	if (x == 2) return x*(x-1)*3 + x;
	return x;
}

int main(){
	ll n, k;
	cin >> n >> k;
	if (k%2){
		ll temp = n/k;
		cout << hoge(temp) << endl;
	}else{
		ll temp1 = n/k;
		ll temp2 = (n+k/2)/k;
		cout << hoge(temp1) + hoge(temp2) << endl;
	}
	return 0;
}