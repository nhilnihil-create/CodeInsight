#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> pi;
#define f first
#define s second
#define FAST ios_base::sync_with_stdio(0); cin.tie(0);
#define all(x) x.begin(),x.end()
typedef pair<pi,int> pii;
#define p(x,y,z) pii(pi(x,y),z)

int taken[21];
int upto;
vector <pii> ans; 
int L;

int32_t main() {
	FAST
	cin >> L;
	
	for (int x = 0;x<21;x++) {
		if ((1 << x) > L) {
			upto = x-1;
			break;
		}
	}

	for (int x = 0;x<upto;x++) {
		ans.push_back(p(x,x+1,(1<<x)));
		ans.push_back(p(x,x+1,0));
	}
	
	int curv = (1 << upto);
	for (int x=0;x<upto;x++) {
		if ((1<< x) & L) {
			ans.push_back(p(x,upto,curv));
			curv += (1 << x);
		}
	}
	
	cout << upto+1 << " " << ans.size() << "\n";
	for (auto cur: ans) {
		cout << cur.f.f+1 << " " << cur.f.s+1 << " " << cur.s << "\n";
	}
	
	
	
}






