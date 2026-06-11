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
	int h, w, a, b;
	cin >> h >> w >> a >> b;
	cout << h*w-w*a-h*b+a*b << endl;
	return 0;
 }

