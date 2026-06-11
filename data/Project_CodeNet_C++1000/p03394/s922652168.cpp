#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <functional>
using namespace std;

#define Rep(b, e, i) for(int i = b; i <= e; i++)
#define Repr(e, b, i) for(int i = e; i >= b; i--)
#define rep(n, i) Rep(0, n-1, i)
#define repr(n, i) Repr(n-1, 0, i)
#define all(v) (v).begin(), (v).end()
#define pb(v) push_back(v)
#define uniq(v) (v).erase(unique(all(v)),(v).end())
#define bitcnt(x) __builtin_popcount(x)
#define fst first
#define snd second
#define ENJYU std::ios::sync_with_stdio(false);std::cin.tie(0);

//vector の中身を出力
template <class T>ostream &operator<<(ostream &o,const vector<T>&v)
{o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}

void solve(void){
	ENJYU;
	int N;
	cin >> N;
	if (N == 3) {
		cout << "2 5 63" << endl;
		return;
	}
	if (N == 4) {
		cout << "2 5 20 63" << endl;
		return;
	}
	if (N == 5) {
		cout << "2 3 4 6 9" << endl;
		return;
	}
	vector <int> zwei, drei, sechs;
	Rep(1, 30000, i) {
		if (i % 6 == 0) sechs.pb(i);
		else if (i % 2 == 0) zwei.pb(i);
		else if (i % 3 == 0) drei.pb(i);
	}
	int rest = 0;
	if (N > 15000) {
		rest = N - 15000;
		N = 15000;
	}
	int k = N / 6;
	rep(4*k, i) {
		cout << zwei[i] << ' ';
	}
	rep(2*k, i) {
		cout << drei[i] << ' ';
	}
	rep(N-k*6+rest, i) {
		cout << sechs[i] << ' ';
	}
	cout << endl;
}

int main(void){
	solve();
	//cout << "yui(*-v・)yui" << endl;
	return 0;
}
