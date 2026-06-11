#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <functional>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cassert>
#define InfL 1000000000
#define InfLL 1000000000000000000LL
#define mod 1000000007
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rrep(i,n) for(int (i)=(n-1);(i)>=(0);(i)--)
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<db> vd;

int main() {
	ll H, W, N;
	cin >> H >> W >> N;
	vl X(N), Y(N);
	vector<vl> Xobslist(H);
	vl Xobsnum(H, 0);
	ll ans = H;
	rep(i, N) {
		cin >> X[i] >> Y[i];
		X[i]--;
		Y[i]--;
		Xobslist[X[i]].push_back(Y[i]);
		Xobsnum[X[i]]++;
	}
	ll can_go_to_Y = 0; // Y方向到達可能範囲 : 0 <= y <= can_go_to_Y
	rep(x, H) { // 上から順に見る
		if (x == 0)
			continue;
		ll xobsnum = Xobsnum[x];
		bool can_stop = false;
		bool can_go_to_Y_will_inc = true; // (x, can_go_to_Y + 1)に障害物がなければY方向到達可能範囲が1増える
		rep(i, xobsnum) {
			int y = Xobslist[x][i];
			if (y <= can_go_to_Y) {
				can_stop = true;
				break;
			}
			else if (y == can_go_to_Y + 1)
				can_go_to_Y_will_inc = false;
		}
		if (can_stop) {
			ans = x;
			break;
		}
		if (can_go_to_Y_will_inc)
			can_go_to_Y++;
	}
	cout << ans << endl;
	return 0;
}