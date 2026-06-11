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
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if ((abs(b - a) <= d && abs(c - b) <= d) || abs(a - c) <= d) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
