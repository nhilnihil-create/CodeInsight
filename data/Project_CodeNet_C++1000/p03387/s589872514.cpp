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
	int a, b, c;
	cin >> a >> b >> c;
	int maxi = max(a, max(b, c));
	if (maxi%2 == (a+b+c)%2) cout << (3*maxi - a - b - c)/2 << endl;
	else cout << (3*(maxi+1) - a - b - c)/2 << endl;
	return  0;
}