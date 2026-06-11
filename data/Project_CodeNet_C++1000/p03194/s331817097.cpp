#include <iostream>
#include <cmath>
using namespace std;

int main() {
	long long n, p, m = 1, q = 2;

	cin >> n >> p;

	while(q <= sqrt(p)){
		int i = 0;
		while(p % q == 0){
			p /= q;
			i++;
		}
		for(int j = 0;  j < (i / n); j++)
			m *= q;
		q++;
	}

	if(n == 1)
		m *= p;

	cout << m << endl;

	return 0;
}