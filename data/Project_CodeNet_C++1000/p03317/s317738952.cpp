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
	int n, k;
	cin >> n >> k;
	if (n <= k){
		cout << 1 << endl;
		return 0;
	}
	n -= 2*k;
	cout << (n+k-1)/(k-1) + 2 << endl;
	return 0;
}