#include <iostream>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <deque>
#include <map>
const int MOD = 1e9+7;
typedef long long ll;
using namespace std;


ll llmax(ll x, ll y){
	if (x > y) return x;
	return y;
}

int main(){
	int n;
	cin >> n;
	if (n == 1){
		cout << "Hello World" << endl;
	}else{
		int a, b;
		cin >> a >> b;
		cout << a + b << endl;
	}
	return 0;
}