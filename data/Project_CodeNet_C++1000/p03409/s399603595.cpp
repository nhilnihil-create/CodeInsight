#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<string>
#include<limits.h>
#include<utility>
#include<vector>
#include<tuple>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i,n) for(int i=0;i<n;i++)
#define ALL(A) A.begin(),A.end()


bool pC(const P & a, const P & b) {
	return a.second > b.second;
}
int main() {
	int n;
	cin >> n;
	vector<P> r(n);
	vector<P> b(n);
	rep(i, n)cin >> r[i].first >> r[i].second;
	rep(i, n)cin >> b[i].first >> b[i].second;
	sort(r.begin(), r.end(),pC);
	sort(b.begin(), b.end());
	vector<bool> used(n, false);
	int ans=0;
	rep(i, n) {
		rep(j, n) {
			if (!used[j]&&b[i].first > r[j].first&& b[i].second > r[j].second) {
				ans++;
				used[j] = true;
				//cout << b[i].first << " " << b[i].second << endl;
				//cout << r[j].first << " " << r[j].second << endl;
				//cout << endl;
				break;
			}
		}
	}
	cout << ans << endl;
}

