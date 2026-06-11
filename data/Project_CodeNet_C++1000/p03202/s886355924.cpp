
#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;
using ll = long long;
#define f(i,a,b) for (int i = a; i < b; i++)
#define fr(i,a,b) for (int i = b-1; i >= a; i--)

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	int a[n]; f(i,0,n) cin>>a[i];
	auto valid = [&](int k) {
		map<int,int> s;
		f(i,1,n) if (a[i]<=a[i-1]) {
			int j = a[i]-1;
			for (auto it = s.upper_bound(j); it != s.end(); it = s.erase(it));
			for (pii pp : s) if (pp.first > j) 
				s[pp.first] = 0;
			while (j >= 0) {
				if (++s[j] == k) s[j--] = 0;	
				else break;
			}
			if (j == -1) return 0;
		}
		return 1;
	};
	bool found = 1;
	f(i,1,n) if (a[i]<=a[i-1])
		found = 0;
	if (n==1 || found) cout << 1 << endl;
	else {
		int lo = 2, hi = n;
		while (lo<=hi) {
			int mid = (lo+hi)/2;
			if (valid(mid)) hi = mid-1;
			else lo = mid+1;
		}
		cout << lo << endl;
	}
	return 0;
}
