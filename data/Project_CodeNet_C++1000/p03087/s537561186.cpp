#include <bits/stdc++.h>
using namespace std;
#define ll          long long
#define vl          vector<ll>
#define vi          vector<int>
#define pi          pair<int,int>
#define pl          pair<ll,ll>
#define all(a)      a.begin(),a.end()
#define mem(a,x)    memset(a,x,sizeof(a))
#define pb          push_back
#define mp          make_pair
#define F           first
#define S           second
#define endl 		"\n"
#define rep(i,a,b)  for(int i=a;i<b;i++)
#define fast_io     std::ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define trace(...) ZZ(#__VA_ARGS__, __VA_ARGS__);
template <typename Arg1> void ZZ(const char* name, Arg1&& arg1) {std::cerr << name << " = " << arg1 << endl;}
template <typename Arg1, typename... Args>void ZZ(const char* names, Arg1&& arg1, Args&&... args)
{
	const char* comma = strchr(names + 1, ',');
	std::cerr.write(names, comma - names) << " : " << arg1;
	ZZ(comma, args...);
}

void solve() {
	string s;
	int n, m;
	cin >> n >> m;
	cin >> s;
	vi a(n + 1, 0);
	s = "*" + s;
	for (int i = 1; i < n; i++) {
		string str = s.substr(i, 2);
		if (str == "AC")a[i] += 1;
	}
	vi pre(n + 1, 0);
	int rs = 0;
	rep(i, 1, n + 1) {
		rs += a[i];
		pre[i] = rs;
	}
	rep(i, 0, m) {
		int l, r;
		cin >> l >> r;
		int ans = pre[r] - pre[l - 1];
		if (a[r] == 1)ans--;
		cout << ans << endl;
	}
}
int main() {
	fast_io;
	int t = 1;
	// cin>>t;
	while (t--) {
		solve();
	}
	// cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
	return 0;
}