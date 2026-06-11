#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef long long ll;

int main() {
	int N,c=0;
	ll w=0;
	cin >> N;
	vector<ll> A(N),B(N),d;

	rep(i,N)
		cin >> A.at(i);
	rep(i,N) {
		cin >> B.at(i);
		if(B.at(i)-A.at(i) > 0) {
			w += B.at(i)-A.at(i);
			++c;
		}
		if(A.at(i)-B.at(i) > 0)
			d.push_back(A.at(i)-B.at(i));
	}

	sort(d.begin(), d.end(), greater<ll>());
	if(w > 0)
		rep(i,d.size()) {
			w -= d.at(i);
			++c;
			if(w <= 0)
				break;
		}

	cout << ((w<=0) ? c : -1) << endl;
}