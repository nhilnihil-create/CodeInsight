#include <iostream>
#include <cstdlib>
#include <time.h>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <array>
#include <string>
#include <iomanip>
#include <cmath>
#define _USE_MATH_DEFINES
using namespace std;

typedef long long int ll;

int main(){
	cin.sync_with_stdio(false);
	cin.tie(0);
	ll a, b;
	cin >> a >> b;
	cout << max({a+a-1, a+b, b+b-1});
	return 0;
}