#include <bits/stdc++.h>
#define st first
#define nd second

using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

const long long N = 100100;
long long n, l[N], r[N];
set <pair<long long, long long> > sl, sr;

void err(long long i) {
	sl.erase({-l[i], i});
	sr.erase({r[i], i});
}

void go_left(long long & ans, long long & last, long long &ok) {
	if(sl.empty())  ok = 0;
	auto x = *sl.begin();
	x.st *= -1;
	// dbg(x, last);
	if(x.st > last) ans += (x.st - last), last = x.st;
	else ok = 0;
	
	err(x.nd);
}

void go_right(long long & ans, long long &last, long long &ok) {
	if(sr.empty())  ok = 0;
	auto y = *sr.begin();
	// dbg(y, last);
	if(y.st < last) ans += (last - y.st), last = y.st;
	else ok = 0;

	err(y.nd);
}

long long try1() {
	long long ok = 1, ans = 0;

	long long last = 0;

	while(ok) {
		go_left(ans, last, ok);
		if(!ok) break;
		go_right(ans, last, ok);
	}
	ans += abs(last);
	return ans;
}


long long try2() {
	long long ok = 1, ans = 0;

	long long last = 0;

	while(ok) {
		go_right(ans, last, ok);
		if(!ok) break;
		go_left(ans, last, ok);
	}
	ans += abs(last);
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n;
	for(long long i = 1; i <= n; i++) {
		cin >> l[i] >> r[i];
		sl.insert({-l[i], i});
		sr.insert({r[i], i});
	}

	auto ssl = sl;
	auto ssr = sr;
	long long ans1 = try1();
	dbg_ok;
	sl = ssl;
	sr = ssr;
	long long ans2 = try2();

	dbg(ans1, ans2);

	cout << max(ans1, ans2) << '\n';
}	

