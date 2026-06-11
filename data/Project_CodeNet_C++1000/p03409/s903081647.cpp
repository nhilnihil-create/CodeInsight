#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int,int> pi;
#define f first
#define s second
#define FAST ios_base::sync_with_stdio(0); cin.tie(0);
typedef pair<pi,int> pii;

int n;
set <int> coords;
vector <pii> points;
//0 is red, 1 is blue

int main() {
	FAST
	cin >> n;
	for (int i =0;i<n;i++) {
		int x,y; cin >> x >> y;
		points.push_back(pii(pi(x,y),0));
	}
	for (int i=0;i<n;i++) {
		int x,y; cin >> x >> y;
		points.push_back(pii(pi(x,y),1));
	}
	sort(points.begin(),points.end());
	int ans = 0;
	for (auto cur: points) {
		int y = cur.f.s;
		if (cur.s == 0) { // red
			coords.insert(y);
		} else { // blue
			auto it = coords.lower_bound(y);
			if (it == coords.begin()) continue;
			it--;
			//cout << (*it) << "\n";
			coords.erase(it);
			ans++;
			//cout << cur.f.f << " " << y << " " << ans << "\n";
		}
	}
	cout << ans;
}	

