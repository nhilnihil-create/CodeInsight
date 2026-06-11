#define _CRT_SECURE_NO_WARNINGS
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<functional>
#include<iomanip>
#include<iostream>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<utility>
#include<vector>

#define ll long long
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define FORR(i,a,b) for(int i=(a);i>=(b);--i)
#define REPR(i,n)   FORR(i,n,0)

using namespace std;

double f(double x, double l, double r, double v) {
	if (l <= x && x <= r) {
		return v;
	}
	else if (x < l) {
		return v + l - x;
	}
	else {
		return v - r + x;
	}
}

int main() {
	int N;
	double v[102] = { 0 }, t[102] = { 0 }, s[102] = { 0 };
	cin >> N;
	REP(i, N) {
		cin >> t[i];
	}
	REP(i, N) {
		cin >> v[i];
	}
	REP(i, N) {
		s[i + 1] = s[i] + t[i];
	}
	
	double dt = 0.5, ans = 0, v1 = 0, v2;
	vector<double> vec;
	REP(i, (int)s[N] * 2) {
		REP(j, N) {
			double y = f((double)(i + 1)*dt, s[j], s[j + 1], v[j]);
			vec.push_back(y);
		}
		vec.push_back(f((double)(i + 1)*dt, 0, 0, 0));
		vec.push_back(f((double)(i + 1)*dt, s[N], s[N], 0));
		double tmp = 1000000;
		REP(k, vec.size()) {
			if (tmp > vec[k]) {
				tmp = vec[k];
			}
		}
		if (tmp >= v1) {
			v2 = v1 + min(tmp - v1, dt);
		}
		else {
			v2 = v1 - min(dt, v1 - tmp);
		}
		ans += (v1 + v2)*0.25;
		//cout << i << " " << v1 << " " << v2 << " " << ans << endl;
		v1 = v2;
		vec.clear();

	}


	cout << fixed;
	cout << setprecision(5) << ans << endl;


	return 0;
}