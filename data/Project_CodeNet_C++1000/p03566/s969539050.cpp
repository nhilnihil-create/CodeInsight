#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include <cmath>
#include <limits>
#include <utility>
#include <map>
#include <iomanip>




#define rep(p,q) for(int i = p;i < q;i++)
#define ll long long

using namespace std;

const int cons = 1e9 + 7;

int n;
vector<double> v;
vector<double> l;
vector<double> r;
double speed(double t) {
	double ret = 100;
	rep(0, n + 2) {
		double reti = 0;
		if (t <= l[i]) reti = v[i] + l[i] - t;
		else if (r[i] <= t) reti = v[i] + t - r[i];
		else reti = v[i];
		ret = min(ret, reti);
	}
	return ret;
}

//D

int main(void) {

	cin >> n;
	v = vector<double>(n + 2);
	l = vector<double>(n + 2);
	r = vector<double>(n + 2);
	v[0] = 0; l[0] = 0; r[0] = 0;
	v[n + 1] = 0;
	int T = 0;
	rep(1, n + 1) {
		int ti = 0;
		cin >> ti;
		r[i] = r[i - 1] + ti;
		l[i] = r[i - 1];
		T += ti;
	}
	l[n] = r[n - 1];
	rep(1, n + 1) {
		cin >> v[i];
	}
	l[n + 1] = T; r[n + 1] = T;
	double ans = 0;
	for (double i = 0; i < T; i += 0.5) {
		double s1 = speed(i);
		double s2 = speed(i + 0.5);
		ans += 0.25*(s1 + s2);
	}
	cout << fixed << setprecision(3) << ans << endl;
}