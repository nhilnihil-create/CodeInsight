#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int divisor(long long N) {
	vector<long long> res;
	
	for (long long a = 1; a*a <= N; a++) {
		if (N%a != 0) continue;

		long long b = N / a;

		if (b == a)
			res.push_back(a);
		else {
			res.push_back(a);
			res.push_back(b);
		}
	}

	return res.size();
}

int main(void) {
	
	long long N;

	cin >> N;
	int c = 0;

	for (long long i = 1; i <= N; i = i + 2){
		int a = divisor(i);
		if (a == 8)
			c++;
	}

	cout << c << endl;

}