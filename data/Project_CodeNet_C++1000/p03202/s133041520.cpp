#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(V) V.begin(),V.end()

const ll MOD = 1000000007;

int N;
ll A[200010];

bool f(ll md) {
	map<ll, ll> M;
	M.insert({ 1,0 });
	ll a, b;
	for (int i = 1;i < N;i++) {
		if (A[i - 1] < A[i])continue;
		else {
			if (M.count(A[i])) M[A[i]]++;
			else M.insert({ A[i],1 });
			while (1) {
				auto it = M.end();
				it--;
				tie(a, b) = *it;
				if (a == A[i])break;
				while (1) {
					b /= md;
					a--;
					if (b == 0)break;
					if (M.count(a)) {
						M[a] += b;
						break;
					}
				}
				M.erase(it);
			}
		}
	}

	while (1) {
		auto it = M.end();
		it--;
		tie(a, b) = *it;
		if (a == 1)break;
		while (1) {
			b /= md;
			a--;
			if (b == 0)break;
			if (M.count(a)) {
				M[a] += b;
				break;
			}
		}
		M.erase(it);
	}
	return M[1] < md;
}

ll binary(ll ng, ll ok) {
	if (ng + 1 == ok)return ok;
	ll mid = (ng + ok) / 2;
	if (f(mid)) {
		return binary(ng, mid);
	}
	else {
		return binary(mid, ok);
	}
}

int main() {
	/*
	random_device rnd;
	mt19937 mt(rnd());
	uniform_int_distribution<> randA(1, 1000000000);
	*/

	cin.tie(0); ios::sync_with_stdio(false);

	cin >> N;
	
	for (int i = 0;i < N;i++)cin >> A[i];
	//for (int i = 0;i < N;i++)A[i] = randA(mt);

	//単調増加なら1、そうでなければ2以上
	for (int i = 1;i < N;i++) {
		if (A[i - 1] >= A[i]) {
			cout << binary(1, 200000) << endl;
			return 0;
		}
	}
	cout << 1 << endl;
	return 0;
}