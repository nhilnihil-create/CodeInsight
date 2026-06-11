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
	int N,K;
	cin >> N >> K;
	vector<int> X(N);
	rep(i,N) cin >> X[i];
	vector<ll> acc(N-K+1);
	ll mini = 1e18;
	rep(i,N-K+1) {
		if(X[i+K-1] >= 0 && X[i] >= 0) acc[i] = X[i+K-1];
		else if(X[i+K-1] <= 0 && X[i] <= 0) acc[i] = abs(X[i]);
		else acc[i] = min(X[i+K-1] + X[i+K-1] - X[i], abs(X[i]) + abs(X[i] - X[i+K-1]));
		chmin(mini, acc[i]);
	}
	cout << mini << endl;

  return 0;
}
