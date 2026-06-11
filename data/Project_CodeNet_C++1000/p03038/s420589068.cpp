#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define size(a) int((a).size())
#define present(c, x) (c.find(x) != c.end()) 

template <class T>
void printArray(vector<T> arr) {for (T a: arr) cout << a << '\n';}
void printVerdict(bool verdict) {cout << (verdict ? "YES": "NO") << '\n';}
void printDecimal(double d) {printf("%.9f\n", d);}
bool inrange(int val, int start, int end) {return val >=start && val <= end;}
template <class T1, class T2, class T3> 
void printTuple(tuple<T1, T2, T3> t) {cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << '\n';}
template <class T1, class T2>
void printPair(pair<T1, T2> p) {cout << p.first << " " << p.second << '\n';}

class myComparator {
public: 
	int operator() (pair<int, int> a, pair<int, int> b) {
		return a.second > b.second;
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,m; cin >> n >> m;
	int a[n];
	for (int i = 0; i<n; i++) cin >> a[i];
	vector<pair<int, int>> bc(m);
	for (int i = 0; i<m; i++) {
		int b,c; cin >> b >> c;
		bc[i] = make_pair(b, c);
	}
	sort(a, a+n);
	sort(bc.begin(), bc.end(), myComparator());
	ll curr_ret = 0;
	int ptr1 = 0, ptr2 = 0;
	for (int i = 0; i<m; i++) {
		if (a[ptr1] < bc[i].second) {
			ptr2 = ptr1;
			while (ptr2 < n && a[ptr2] < bc[i].second && bc[i].first > 0) {
				a[ptr2] = bc[i].second; 
				ptr2++;
				bc[i].first--;
			}
			ptr1 = ptr2;
		}
	}
	for (int i = 0; i<n; i++) curr_ret += a[i];
	cout << curr_ret << '\n';
}

