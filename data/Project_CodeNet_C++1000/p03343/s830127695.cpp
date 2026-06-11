#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> pi;
#define f first
#define s second
#define FAST ios_base::sync_with_stdio(0); cin.tie(0);
#define all(x) x.begin(),x.end()

const int maxn = 2010;
const int INF = LLONG_MAX/2;

int n,k,q;
int A[maxn];

int32_t main() {
	FAST
	cin >> n >> k >> q;
	int ans = INF;
	for (int i=0;i<n;i++) cin >> A[i];
	for (int i=0;i<n;i++) {
		int x = A[i]; // Fix x value
		
		vector <int> curv,options;
		for (int j=0;j<n;j++) {
			if (A[j] >= x) curv.push_back(A[j]);
			else { //1 segment
				sort(all(curv));
				if (curv.size() >= k) {
					curv.resize(curv.size()-k+1);
					for (auto xd: curv) options.push_back(xd);
				}
				curv.clear();
			}
			//cout << A[i] << " " << A[j] << " " << options.size() << "\n";
		}
		sort(all(curv));
		if (curv.size() >= k) {
			curv.resize(curv.size()-k+1);
			for (auto xd: curv) options.push_back(xd);
		}
		
		sort(all(options));
		if (options.size() >= q) ans = min(ans, options[q-1] - x);
	}
	cout << ans;
}






