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
ll xoruptoK(ll k) {
	if (k % 2 == 0) {
		ll d = k / 2;
		if (d % 2 == 0)return k;
		else return k ^ 1ll;
	}
	else {
		ll d = (k + 1) / 2;
		if (d % 2 == 0)return 0;
		else return 1;
	}
}
void solve() {
	ll a, b;
	cin >> a >> b;
	// trace(xoruptoK(a - 1), xoruptoK(b))
	a = max(a - 1, 0ll);
	cout << (xoruptoK(b)^xoruptoK(a));

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