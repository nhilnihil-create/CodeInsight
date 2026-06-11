#include <numeric>
#include <iostream>
#include <array>
#include <string>
#include <vector>
#include <cassert>
#include <algorithm>
#include <math.h> 
#include <set>
#include <map>
#include <utility>
#include <deque>
#include <queue>


using namespace std;

#define ll long long int
#define rep(i, n) for(ll i = 0; i < n; i++)
#define repp(i, n) for(int i = 1; i <= n; i++)
#define sort(v) sort((v).begin(), (v).end())
#define riverse(v) reverse((v).begin(), (v).end())
#define pb push_back
#define mp make_pair
#define all(a)  (a).begin(),(a).end()
using vi = vector<int>;
using vs = vector<string>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vi>;
const ll MOD = 1e9 + 7;
vi alphabet = { 'a','b','c','d','e','f','g','h','i','j','k','l','m',
               'n','o','p','q','r','s','t','u','v','w','x','y','z' };



int main() {
	int N;
	cin >> N;
	vvi F(N, vi(10));
	rep(i, N) {
		rep(j, 10) {
			cin >> F[i][j];
		}
	}
	vvi P(N, vi(11));
	rep(i, N) {
		rep(j, 11) {
			cin >> P[i][j];
		}
	}
	vi ans;
	for (int bit = 1; bit < (1 << 10); ++bit) {
		vi c(N);
		int sum = 0;
		rep(i, 10) {
			if (bit & (1 << i)) {
				rep(j, N) {
					if (F[j][i] == 1) {
						c[j]++;
					}
				}
			}
		}
		rep(i, N) {
			sum += P[i][c[i]];
		}
		ans.push_back(sum);
	}
	sort(ans);
	riverse(ans);
	cout << ans[0] << endl;
}