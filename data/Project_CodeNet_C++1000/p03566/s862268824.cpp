#include <bits/stdc++.h>
using namespace std;

#define li long long int
#define rep(i, to) for (li i = 0; i < ((li)(to)); i++)
#define repp(i, start, to) for (li i = (li)(start); i < ((li)(to)); i++)
#define allof(v) (v).begin(), (v).end()


#define MOD 1000000007

li n;
li t[222];
li v[111];

li lb_left[111];
li lb_right[111];

inline double calc(li idx) {
	li haba_left = v[idx] - lb_left[idx];
	li haba_right = v[idx] - lb_right[idx];
	double res = 0.0;
	if (haba_left + haba_right <= t[idx]) {
		// 道中で上限にぶつかる
		res += v[idx] * (t[idx] - (haba_left + haba_right));
		res += (lb_left[idx] + v[idx]) * haba_left / 2.0;
		res += (lb_right[idx] + v[idx]) * haba_right / 2.0;
	} else {
		// どこかでカックンする
		li ma = max(lb_left[idx], lb_right[idx]);
		li mi = min(lb_left[idx], lb_right[idx]);
		res += (ma - mi) * (ma + mi) / 2.0;
		li rest = t[idx] - (ma - mi);
		double rest2 = rest / 2.0;
		res += (ma + ma + rest2) * rest2;
	}
	return res;
}

int main(void)
{
	cin >> n;
	rep(i, n) {
		cin >> t[i];
	}
	rep(i, n) {
		cin >> v[i];
		lb_left[i] = v[i];
		lb_right[i] = v[i];
	}
	lb_left[0] = 0;
	lb_right[n - 1] = 0;

	for (li i = 0; i < n - 1; ++i) {
		lb_right[i] = min(lb_left[i + 1], min(lb_left[i] + t[i], lb_right[i]));
		lb_left[i + 1] = min(lb_right[i], lb_left[i + 1]);
	}

	for (li i = n - 1; i > 0; i--) {
		lb_left[i] = min(lb_right[i - 1], min(lb_right[i] + t[i], lb_left[i]));
		lb_right[i - 1] = min(lb_right[i - 1], lb_left[i]);
	}
	double res = 0.0;
	rep(i, n) {
		res += calc(i);
	}
	printf("%.14f\n", res);



	return 0;
}