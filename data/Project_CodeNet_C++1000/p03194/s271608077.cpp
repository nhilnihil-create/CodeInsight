#include<iostream>
#include<string>
#include<vector>
#include<stdio.h>
#include<cstdio>
#include<algorithm>
#include<stdlib.h>
#define _USE_MATH_DEFINES
#include<math.h>
#include<numeric>
#include<iomanip>
#include<queue>
#include<stack>
#include<iterator>
#include<functional>
#include<string.h>
//#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
//namespace mp = boost::multiprecision;

int main() {
	unsigned long long int n, p; cin >> n >> p;
	unsigned long long int tmp = 0;
	float t = 1.0000000000000000 / n;
	unsigned long long int s = pow(p, t);
	//if (s < 0) {
	//	s = 1;
	//}
	for (unsigned long long int i = s; i>0; i--) {
		unsigned long long k = pow(i, n);
		if (p%k == 0) {
			tmp = i;
			break;
		}
	}
	cout << tmp << endl;
}
	
