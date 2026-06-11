#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

#define DMAX 
#define NMAX 
#define MMAX 

using namespace std;

int n, k, a, b;

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}


long long cb(int low, int high) {
	while(low != high) {
		int mid = (low + high + 1) / 2;
		long long j = (a * b / mid);
		if(mid * j == a * b) j--;
		if(mid > j) // nu e ok mid-ul
			high = mid - 1;
		else low = mid;
	}
	return 1;
}

long long solve(long long a, long long b)
{
	if(b > a) swap(a, b);
	long long ans = 2 * b - 1;
	if(a == b || a == b + 1)
		ans--;
	//ans++; // b* (a - 1)
	// dbg(ans);
	// int maxb = cb(b + 1, a - 2);

	if(a - b > 1000000) {
		int i;
		long long maxj = a - 2;
		for(i = b + 1; i < a; i+=10000) {
			long long j = (a * b / i);
			if(i * j == a * b) j--;
			// if(j > maxj) j = maxj;
			// maxj = j - 1;
			// dbg(i);
			// dbg(j);
			if(i >= j) break;
			else ans += 20000;
		}
		i -= 10000;
		ans -= 20000;
		for(; i < a; i++) {
			long long j = (a * b / i);
			if(i * j == a * b) j--;
			// if(j > maxj) j = maxj;
			// maxj = j - 1;
			// dbg(i);
			// dbg(j);
			if(i > j) break;
			if(i == j)
				ans++;
			else ans += 2;
		}
		
		return ans;
	}


	long long maxj = a - 2;
	for(int i = b + 1; i < a; i++) {
		long long j = (a * b / i);
		if(i * j == a * b) j--;
		// if(j > maxj) j = maxj;
		// maxj = j - 1;
		// dbg(i);
		// dbg(j);
		if(i > j) break;
		if(i == j)
			ans++;
		else ans += 2;
	}


	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; i++)	{
		cin >> a >> b;
		cout << solve(a, b) << '\n';
	}
}