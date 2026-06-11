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


int main(){
	int a, b, c;
	cin >> a >> b >> c;
	cout << max(a, max(b, c)) - min(a, min(b, c)) << endl;

	return 0;
}