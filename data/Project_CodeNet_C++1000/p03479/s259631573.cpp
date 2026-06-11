#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<cmath>
#include<list>
#include<set>
#include<map>

using namespace std;
long long MOD = 1000000007LL;
const double PI = 3.14159265358979323846;
#undef INT_MIN
#undef INT_MAX
#define INT_MIN -2147483648
#define INT_MAX 2147483647
#define endl "\n"

int main() {
	unsigned long long X, Y;
	cin >> X >> Y;
	
	int count = 0;
	while (1) {
		if (X <= Y)++count;
		else break;

		X *= 2;
	}

	cout << count << endl;
	return 0;
}