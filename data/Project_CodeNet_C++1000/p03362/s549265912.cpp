#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define rep(i, n) for (int i = 0, i##_len = (int)(n); i < i##_len; i++)
#define reps(i, n) for (int i = 1, i##_len = (int)(n); i <= i##_len; i++)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; i--)
#define rreps(i, n) for (int i = ((int)(n)); i > 0; i--)
#define repi(i, x) \
	for (auto i = (x).begin(), i##_fin = (x).end(); i != i##_fin; i++)
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define mp make_pair
#define pb push_back
typedef vector<int> Vi;
typedef vector<Vi> VVi;
typedef pair<int, int> Pi;
typedef vector<Pi> VPi;
typedef vector<long long> V;
typedef vector<V> VV;
typedef pair<long long, long long> P;
typedef vector<P> VP;
template <class T>
inline bool chmax(T& a, T b) {
	if (a < b) {
		a = b;
		return 1;
	}
	return 0;
}
template <class T>
inline bool chmin(T& a, T b) {
	if (a > b) {
		a = b;
		return 1;
	}
	return 0;
}
const long long INFLL = 1LL << 60;
const int INF         = 1 << 30;
const double PI       = acos(-1);
Vi getlist(int terget) {
	Vi res;
	vector<bool> box(terget, true);
	box[0] = false;
	box[1] = false;
	for (int i = 2; i < terget; i++) {
		if (box[i] == false) {
			continue;
		}
		

		if(i%5==1){
		res.push_back(i);
	//	clog << i << endl;
		}
		for (int j = i * 2; j < terget; j += i) {
			box[j] = false;
		}
	}
	clog << "prime" << (res.size()) << endl;
	return res;
}
Vi solve(int n) {
	Vi res(n);
	Vi per = getlist(55556);
	rep(i, n) { res[i] = per[i]; }
	return res;
}
int main() {
	int n;
	cin >> n;
	Vi ans = solve(n);
	repi(itr, ans) {
		cout << (*itr);
		if (itr != ans.end() - 1) {
			cout << " ";
		}
	}
	cout << endl;
}
/*
3 2 6 6 18 30 22
*/