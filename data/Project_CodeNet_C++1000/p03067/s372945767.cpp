#include<iostream>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<map>
#include<iomanip>
#include<sstream>
#include<vector>
#include<stack>
#include<math.h>
#include<queue>
#include<complex>
using namespace std;


int main() {
	complex<long double>cmpmp;
	const long long int mod = 1000000007;
	map<long long int, long long int>mp;
	//cout << fixed << setprecision(10);
	long long int N, A, B, h[200] = {}, left = 0, right = 1000000000, bomb, sum[15] = {};
	string str;
	cin >> h[0]>>h[1]>>h[2];
	A = h[2];
	sort(h, h + 3);
	if (h[1] == A) { cout << "Yes"; }
	else { cout << "No"; }
}