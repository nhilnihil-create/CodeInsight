#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
	ll N, H;
	cin >> N >> H;
	vector<ll> a(N);
	vector<ll> b(N);
	rep(i, N){
		cin >> a[i] >> b[i];
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	ll cnt = 0;
	while (H > 0){
		ll tmp_a, tmp_b;
		if (b.size() > 0){
			tmp_a = a.back();
			a.pop_back();
			tmp_b = b.back();
			b.pop_back();
			if (tmp_a >= tmp_b){
				while (H > 0){
					cnt++;
					H -= tmp_a;
				}
				break;
			}
			else {
				H -= tmp_b;
				a.push_back(tmp_a);
				cnt += 1;
			}
		}
		else {
			tmp_a = a.back();
			while (H > 0){
				cnt++;
				H -= tmp_a;
			}
			break;
		}
	}
	cout << cnt << endl;
	return 0;
}
