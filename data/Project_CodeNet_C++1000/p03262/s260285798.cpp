#include<iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include <map>

using namespace std;
int gcd(int x, int y) { return (x % y) ? gcd(y, x % y) : y; }
int main()
{
	long N,K;

	cin >> N >> K;

	vector<long> longlist(N);
	long num = 0;

	for (long i = 0; i < N; i++)
	{
		cin >> num;
		
		longlist[i] = abs(num-K);
	}

	long n, a, b;
	n = longlist.size();
	a = longlist[0];

	for (long i = 1; i < n; i++) {
		b= longlist[i];
		a = gcd(a, b);
	}

	cout << a << endl;

	return 0;


}

