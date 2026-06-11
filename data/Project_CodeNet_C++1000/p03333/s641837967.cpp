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
#define Pqaz(T) priority_queue<T,vector<T>,greater<T>>
#define Pqza(T) priority_queue<T>
#define ENJYU std::ios::sync_with_stdio(false);std::cin.tie(0);

typedef long long ll;
typedef pair<ll, ll> llP;
typedef pair<int, int> P;

//vector の中身を出力
template <class T>ostream &operator<<(ostream &o,const vector<T>&v)
{o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}

void solve(void){
	int N;
	cin >> N;
	vector <int> ls(N+1, 0), rs(N+1, 0);
	rep(N, i) {
		cin >> ls[i] >> rs[i];
	}
	sort(all(ls));
	sort(all(rs));
	reverse(all(ls));
	ll ans = 0;
	rep(N+1, i) {
		if (ls[i] > rs[i]) {
			ans += 2 * (ls[i] - rs[i]);
		}
	}
	cout << ans << endl;
}

int main(void){
	solve();
	//cout << "yui(*-v・)yui" << endl;
	return 0;
}
