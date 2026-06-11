#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main() {
	int N,r;
	double s=0, m=1e9;
	cin >> N;
	vector<double> a(N);

	rep(i,N) {
		cin >> a.at(i);
		s += a.at(i);
	}
	s /= N;

	rep(i,N)
		if(abs(a.at(i)-s) < m) {
			m = abs(a.at(i)-s);
			r = i;
		}
	cout << r << endl;
}