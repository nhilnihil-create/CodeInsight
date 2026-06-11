#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
using ll=long long;
using pll=pair<ll,ll>;

#define fi first
#define se second
#define pb push_back
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define MOD 1000000007

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
	int N;
	ll H;
	cin >> N >> H;
	vector<pll> A(N);
	rep(i,N) cin >> A[i].se >> A[i].fi;
	ll d = 0;
	ll maxi = -1, idx = -1;
	rep(i,N) {
		if(maxi < A[i].se) {
			maxi = A[i].se;
		}
	}
	sort(A.begin(), A.end(), greater<>());
	rep(i,N) {
		if(A[i].se == maxi) idx = i;
	}
	int cnt=0, cnt1 = 0;
	//cout << maxi << endl;
	ll H2 = H;
	rep(j,N) {
		if(A[j].fi > maxi) {
			H2 -= A[j].fi;
			cnt1++;
			if(H2 <= 0) break;
		}
	}
	if(H2>0) cnt1 = 1e9;
	//cout << cnt1 << endl;
	rep(j,N) {
		//cout << A[j].fi << " " << A[j].se << " " << H << " " << idx << endl;
		
		if(A[j].fi > maxi && j != idx) {
			H -= A[j].fi;
			cnt++;
			if(H <= 0) break;
		}
	}
	if(H > 0) {
		if(A[idx].fi > A[idx].se) {
			H -= A[idx].fi;
			cnt++;
		}
		if(H > 0) {
			if(H % A[idx].se != 0) cnt++;
			cnt += H / A[idx].se;
		}
	}
	cout << cnt << endl;

  return 0;
}
