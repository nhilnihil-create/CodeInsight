#include<iostream>
#include<algorithm>
#include<string>
#include<iomanip>
#include<vector>
#include<cstring>
#include<stack>
#include<cstdlib>
#include<cmath>
using namespace std;

int main()
{
	long long n, p;
	vector<long long> v;
	cin >> n >> p;

	if (n == 1) {
		cout << p << endl;
		return 0;
	}

	while (p % 2 == 0) {
		v.push_back(2);
		p /= 2;
	}
	for (long long i = 3; p!=1 && i*i <= p; i+=2) {
		if (p % i == 0) {
			v.push_back(i);
			p /= i;
			i-=2;
			continue;
		}
	}
	if (p != 1)
		v.push_back(p);
	int cnt = 0, num = -1, ans = 1;
	for (long long i = 0; i < v.size(); i++) {
		if (v[i] == num)
			cnt++;
		else
			cnt = 1;

		if (cnt == n) {
			ans *= v[i];
			cnt = 0;
		}
		num = v[i];
	}
	cout << ans << endl;
}