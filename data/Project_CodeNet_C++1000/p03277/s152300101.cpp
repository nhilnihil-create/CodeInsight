/*input
10
5 9 5 9 8 9 3 5 4 3

*/
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define mp make_pair
#define int long long
#define N
#define bit(x,y) ((x>>y)&1LL)
#define loop(x) for(int xv=1; xv<=x; xv++)

#define what_is(x) cerr << #x << " is " << x << endl;
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}
template <class T1, class T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &a) {
	return os << '(' << a.first << ", " << a.second << ')';
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &a) {
	os << '[';
	for (unsigned int i = 0; i < a.size(); i++)
		os << a[i] << (i < a.size() - 1 ? ", " : "");
	os << ']';
	return os;
}
template <class T>
ostream &operator<<(ostream &os, const set<T> &a) {
	os << '{';
	for (typename set<T>::iterator it = a.begin(); it != a.end(); it++) {
		typename set<T>::iterator jt = it;
		os << *it << (++jt != a.end() ? ", " : "");
	}
	os << '}';
	return os;
}
template <class T1, class T2>
ostream &operator<<(ostream &os, map<T1, T2> &a) {
	os << "{\n";
	for (typename map<T1, T2>::iterator it = a.begin(); it != a.end(); it++) {
		typename map<T1, T2>::iterator jt = it;
		os << "  " << it->first << ": " << it->second << (++jt != a.end() ? ",\n" : "\n");
	}
	os << '}';
	return os;
}

int n;
vector<int> a, ta;
vector<pair<int, int> > b;

int tree[200010];

int get(int i) {
	int ret = 0;
	i += 100005;
	for (; i < 200010; i += i & -i) {
		ret += tree[i];
	}
	return ret;
}

void update(int i, int val) {
	i += 100005;
	for (; i; i -= i & -i) {
		tree[i] += val;
	}
}

int countArr(int mid) {
	ta.clear(); memset(tree, 0, sizeof(tree));
	for (auto it : a) {
		if (it > mid) ta.push_back(1);
		else ta.push_back(-1);
	}
	// tong duong
	int sum = 0; int ret = 0;
	update(0, 1);
	for (int i = 0; i < n; i++) {
		sum += ta[i];
		ret += get(sum + 1);
		update(sum, 1);
	}
	return ret;
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int t; cin >> t;
		a.push_back(t);
		b.push_back(mp(t, i - 1));
	}
	sort(b.begin(), b.end());
	for (int i = 0; i < n; i++) {
		a[b[i].se] = i;
	}
	int l = 0, r = n - 1;
	int all = n * (n + 1) / 2;
	all = all / 2 + 1;
	while (l != r) {
		int mid = (l + r) / 2;
		int rec = countArr(mid);
		// cout << mid << sp << rec << sp << all << endl;
		if (rec >= all) r = mid;
		else l = mid + 1;
	}
	// cout << b << endl;
	cout << b[l].fi << endl;
}