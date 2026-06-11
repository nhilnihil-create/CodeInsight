#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
using ll=long long;

#define fi first
#define se second
#define pb push_back
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define MOD 1000000007

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
	int n;
	cin >> n;
	vector<int> p(n);
	vector<int> a(n);
	rep(i,n) {
		cin >> p[i];
		a[p[i]-1] = i;
	}
	int renzokuStart = 0;
	int renzokuTimes = 1;
	int maxRenzokuStart = 0;
	int maxRenzokuTimes = -1;
	for(int i=1; i<n; i++) {
		if(a[i-1] < a[i]) {
			renzokuTimes++;
		}
		if(a[i-1] > a[i]) {
			if(renzokuTimes > maxRenzokuTimes) {
				maxRenzokuStart = renzokuStart;
				maxRenzokuTimes = renzokuTimes;
			}
			renzokuStart = i;
			renzokuTimes = 1;
		}
	}
	chmax(maxRenzokuTimes, renzokuTimes);
	cout << n - maxRenzokuTimes << endl;
  return 0;
}
