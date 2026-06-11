#include<iostream>
#include <string>
#include<algorithm>
#include <set>
#include <cmath>
#include<math.h>
using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	long N, P, i, k, j, a,s;
	cin >> N >> P;
	s = (long)pow((double)(P), 1.0 / (double)(N));
	a = 0;
	if (N == 1) a = P;
	else{

		for (i = 1; i <= s + 1; i++) {
			j = (long)pow((double)(i), (double)(N));
			if (P % j == 0) a = i;
			if (P <= j) break;
		}
	}


	cout << a;
	return 0;
}
