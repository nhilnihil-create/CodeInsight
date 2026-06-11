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
	int N;
	cin >> N;
	vl A(N);
	rep(i, N)
		cin >> A[i];
	sort(A.begin(), A.end(), greater<ll>());
	multiset<ll> Aset;
	ll ans = 0;
	rep(i, N)
		Aset.insert(A[i]);
	rep(i, N) {
		if (Aset.find(A[i]) == Aset.end())
			continue;
		Aset.erase(Aset.find(A[i]));
		ll Asum = 1;
		while (1) {
			if (A[i] < Asum)
				break;
			Asum *= 2LL;
		}
		ll Asub = Asum - A[i];
		if (Aset.find(Asub) != Aset.end()) {
			Aset.erase(Aset.find(Asub));
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}