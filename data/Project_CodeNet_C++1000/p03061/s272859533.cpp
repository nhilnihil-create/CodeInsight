#include <bits/stdc++.h>
using namespace std;

template <class T = long long>
class ST {	//非再帰抽象化セグ木
   private:
	int n;
	vector<T> data;
	T unit;
	function<T(T, T)> operation;

   public:
	ST(int _n, function<T(T, T)> _operation, T _unit) : n(_n), operation(_operation), unit(_unit) {
		data.assign(n * 2, unit);
		for(int i = n - 1; i > -1; i--) {
			data[i] = operation(data[i << 1], data[i << 1 | 1]);
		}
	}
	ST(int _n, function<T(T, T)> _operation, T _unit, vector<T> raw_data) : n(_n), operation(_operation), unit(_unit) {
		data.assign(n * 2, unit);
		for(int i = 0; i < n; i++) {
			data[i + n] = raw_data[i];
		}
		for(int i = n - 1; i > -1; i--) {
			data[i] = operation(data[i << 1], data[i << 1 | 1]);
		}
	}
	ST(int _n, function<T(T, T)> _operation, T _unit, T _init) : n(_n), operation(_operation), unit(_unit) {
		data.assign(n * 2, _init);
		for(int i = n - 1; i > -1; i--) {
			data[i] = operation(data[i << 1], data[i << 1 | 1]);
		}
	}

	void update(int idx, T x) {
		idx += n;
		data[idx] = x;
		idx >>= 1;
		while(idx > 0) {
			data[idx] = operation(data[(idx << 1)], data[(idx << 1) | 1]);
			idx >>= 1;
		}
	}

	//お好きな二項演算をどうぞ 抽象化するのはちょっとやりすぎ感
	void add(int idx, T x) { update(idx, data[idx + n] + x); }

	T get(int lef, int rig) {
		T a = unit, b = unit;
		lef += n;
		rig += n;
		while(lef < rig) {
			if(lef & 1) a = operation(a, data[lef]);
			if(rig & 1) b = operation(data[rig - 1], b);
			(lef += 1) >>= 1;
			rig >>= 1;
		}
		return operation(a, b);
	}
};

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	ST<int> st(
		n, [](int a, int b) { return __gcd(a, b); }, 0, a);
	int ans = 0;
	for(int i = 0; i < n; i++) {
		int a, b;
		a = st.get(0, i);
		b = st.get(i + 1, n);
		ans = max(ans, __gcd(a, b));
	}
	cout << ans << endl;
}