#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;


int main() {


	int a, b, c;

	cin >> a >> b >> c;

	int sum = 0;
	int m = -1;
	sum += abs(a - b);
	m = max(abs(a-b), m);
	sum += abs(b - c);
	m = max(abs(b - c), m);
	sum += abs(c - a);
	m = max(abs(c - a), m);

	sum -= m;

	cout << sum << endl;

}