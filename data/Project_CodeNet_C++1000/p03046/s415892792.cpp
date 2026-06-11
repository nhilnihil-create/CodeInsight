#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <iomanip>
#include <stack>
#include <queue>
#include <deque>

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define pb push_back
#define ppb pop_back
#define mkp make_pair
#define F first
#define S second
#define show(a) cerr << #a <<" -> "<< a <<" "
#define fo(a, b, c, d) for(int (a) = (b); (a) <= (c); (a) += (d))
#define foo(a, b, c ,d) for(int (a) = (b); (a) >= (c); (a) -= (d))
//#define int ll

const int N = 200;
const int INF = 1e9;

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	/*for(int m = 3; m <= 3; ++m) {
		vector <int> v;
		for(int i = 0; i <= m; ++i) {
			v.pb(i);
			v.pb(i);
		}
		int n = sz(v) - 1;
		do {
			int ans = -1;
			bool sorry2 = 0;
			for(int i = 0; i <= n; ++i) {
				bool sorry = 0;
				for(int j = i + 1; j <= n; ++j) {
					if(v[i] == v[j]) {
						int res = 0;
						for(int k = i; k <= j; ++k) {
							res ^= v[k];
						}
						if(ans == -1) {
							ans = res;
						}
						else if(ans != res) {
							sorry = 1;
							break;
						}
					}
				}
				if(sorry) {
					sorry2 = 1;
					break;
				}
			}
			if(!sorry2) {
				//st.insert(ans);
				cerr << "\n";
				show(ans); show(m);
				cerr << "v -> ";
				fo(i, 0, n, 1)
					cout << v[i] <<' ';
				cout << "\n";	
			}
		} while(next_permutation(all(v)));
//		show(m);
//		for(int it : st)
//			cout << it <<' ';
//		cout << '\n';
	}
	cerr << "end\n";*/
	int m, k;
	cin >> m >> k;
	if(k == 0) {
		fo(i, 0, (1 << m) - 1, 1) {
			cout << i <<' '<< i <<' ';
		}	
		return 0;
	}
	int res = 0;
	fo(i, 0, (1 << m) - 1, 1) {
		if(k == i)
			continue;
		res ^= i;
	}
	if(res != k) {
		cout << -1;
		return 0;
	}
	fo(i, 0, (1 << m) - 1, 1) {
		if(k == i)
			continue;
		cout << i <<' ';
	}
	cout << k <<' ';
	foo(i, (1 << m) - 1, 0, 1) {
		if(k == i) 
			continue;
		cout << i <<' ';	
	}
	cout << k;
	return 0;
}