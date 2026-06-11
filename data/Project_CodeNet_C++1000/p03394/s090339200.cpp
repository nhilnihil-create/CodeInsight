#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<queue>
#include<stack>
#include<bitset>
using namespace std;
int p = 1000000007;
#define int long long
#define vel vector<long long>
#define vvel vector<vel>
#define rep(i,n) for(long long i=0;i<n;i++)
#define sor(v) sort(v.begin(),v.end())
#define mmax(a,b) a=max(a,b)
#define mmin(a,b) a=min(a,b)
#define mkp make_pair
#define pin pair<int,int>
#define V vector
#define Endl endl
#define veb vector<bool>
#define sq(a) (a)*(a)
#define rev(s) reverse(s.begin(),s.end())
#define end_program(s) cout << s <<endl;return 0
int kai_size = 120001;
vel kai(kai_size, 1);
vel ink(kai_size, 1);
vel dist;
int RE() {
	vel v(3, 2);
	return v.at(4); 
}
int ru(int a, int r) {
	if (r == 0) { return 1; }
	int ans = ru(a, r / 2);
	ans *= ans; ans %= p;
	if (r % 2 == 1) { ans *= a; }
	return ans % p;
}
int inv(int a) {
	return ru(a, p - 2);
}
void make_kai() {
	rep(i, kai_size-1) { kai[i + 1] = (kai[i] * (i + 1)) % p; }
	rep(i, kai_size) { ink[i] = inv(kai[i]); }
}
int com(int n, int r) {
	int ans = kai[n] * ink[r];
	ans %= p; ans *= ink[n - r]; ans %= p;
	return ans;
}
vel dis(int mid1, vvel &way) {
	int n = way.size();
	vel dist(n, -1); dist[mid1] = 0;
	queue<int> q;
	q.push(mid1);
	while (!q.empty()) {
		int st = q.front(); q.pop();
		rep(i, way[st].size()) {
			int to = way[st][i];
			if (dist[to] == -1) {
				dist[to] = dist[st] + 1;
				q.push(to);
			}
		}
	}
	return dist;
}
pin most_far(int now, int n, vvel &way) {
	vel dist1 = dis(now, way);
	pin ans = mkp(-1, 0);
	rep(i, n) {
		if (dist1[i] > ans.first) { ans = mkp(dist1[i], i); }
	}
	return ans;
}

int per(int a, int b) {
	int ans = a % b;
	if (ans < 0) { ans += b; }
	return ans;
}
V<pin> uni(V<pin> &v) {
	sor(v);
	V<pin> ans(1, v[0]);
	for (int i = 1; i < v.size(); i++) {
		if (v[i] != v[i-1]) { ans.push_back(v[i]); }
	}
	v = ans;
	return v;
}
int s_gcd(int a, int b) {
	if (b == 0) { return a; }
	return s_gcd(b, a%b);
}
int gcd(int a, int b) {
	if (a < b) { swap(a, b); }
	return s_gcd(a, b);
}
bool win_first(vel &a) {
	int n = a.size();
	int sum = 0;
	vel odd;
	rep(i, n) {
		sum += a[i] - 1;
		if (a[i] % 2 == 1) { odd.push_back(i); }
	}
	if (sum % 2 == 1) { return true; }
	if (odd.size() == 1) {
		if (a[odd[0]] != 1) {
			a[odd[0]]--;
			int gcd0 = a[0];
			for (int i = 1; i < n; i++) {
				gcd0 = gcd(gcd0, a[i]);
			}
			rep(i, n) { a[i] /= gcd0; }
			return !win_first(a);
		}
	}
	return false;
}
signed main() {
	int n; cin >> n;
	if (n == 3) { cout << 2 << " " << 5 << " " << 63 << endl; return 0; }
	vel a = { 3,9,4,8,2,10,6,12 };
	int m = n / 8;
	vel ans;
	rep(i, m) {
		rep(j, 8) {
			ans.push_back(12 * i + a[j]);
		}
	}
	int ex = n % 8;
	int pl = 12 * m;
	rep(j, (ex / 2) * 2) {
		ans.push_back(pl + a[j]);
	}
	if (ex % 2 == 1) {
		ans.push_back(pl + 6);
	}
	rep(i, n-1) {
		cout << ans[i] << " ";
	}
	cout << ans[n - 1] << endl;
	return 0;
}