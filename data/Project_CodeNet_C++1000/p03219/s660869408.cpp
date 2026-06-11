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


ll llmax(ll x, ll y){
	if (x > y) return x;
	return y;
}


int main(){
	int x, y;
	cin >> x >> y;
	cout << x + y/2 << endl;
	return 0;
}