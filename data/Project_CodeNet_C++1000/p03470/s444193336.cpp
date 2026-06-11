#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<string>
#include<limits.h>
#include<utility>
#include<queue>
#include<vector>
#include<tuple>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i,n) for(int i=0;i<n;i++)
#define ALL(A) A.begin(),A.end()
bool comparator(P a, P b) {
	return a.first / a.second < b.first / b.second;
}

int main() {
	int n;
	cin >> n;
	vector<ll> d(n);
	rep(i, n) {
		cin >> d[i];
	}
	sort(ALL(d));
	ll j = -1;
	ll ans = 0;
	while (upper_bound(ALL(d), j) < d.end()) {
		j = d[upper_bound(ALL(d), j)-d.begin()];
		ans++;

	}
	cout <<ans <<endl;
}
