#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
using ll=long long;

#define fi first
#define se second
#define pb push_back
#define rep(i,n) for(int i=0; i<(int)(n); i++)

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

vector<ll> A;
int N;

void update(int i, ll x) {
	i += N-1;
	A[i] = x;
	while(i > 0) {
		i = (i-1)/2;
		A[i] = max(A[i*2+1], A[i*2+2]);
	}
}

ll query(int a, int b, int k, int l, int r) {
	if(b <= l || r <= a) {
		return 0;
	}
	if(a <= l && r <= b) {
		return A[k];
	}
	else {
		ll c1 = query(a, b, k*2+1, l, (l+r)/2);
		ll c2 = query(a, b, k*2+2, (l+r)/2, r);
		return max(c1, c2);
	}
}

int main() {
	int n;
	cin >> n;
	vector<int> h(n), a(n);
	rep(i,n) cin >> h[i];
	rep(i,n) cin >> a[i];

	N = 1;
	while(N < n) N *= 2;
	A = vector<ll>(2*N-1, 0);
	rep(i,n) {
		ll temp = query(0, h[i], 0, 0, N);
		update(h[i]-1, temp + a[i]);
	}
	cout << query(0, N, 0, 0, N) << endl;
	//cout << A[0] << endl;
	
	

  return 0;
}
