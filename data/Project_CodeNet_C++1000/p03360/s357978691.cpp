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
	int a, b, c, k;
	cin >> a >> b >> c >> k;
	cout << max(a, max(b, c))*(pow(2, k)-1) + a + b + c << endl;
	return 0;
}
