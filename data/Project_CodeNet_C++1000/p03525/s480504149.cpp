#include <bits/stdc++.h>
const int INF = 1e9;
const int MOD = 1e9+7;
const long long LINF = 1e18;
#define dump(x)  cout << 'x' << ' = ' << (x) << ` `;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define FOREACH(x,a) for(auto& (x) : (a) )
typedef long long ll;
using namespace std;
typedef pair<ll, ll> P;

template<typename T>
void print(vector<T> &x) {
	int n = x.size();
	rep(i,n) {
		cout << x[i];
		if (i!=n-1) cout<<" ";
		else cout << endl;
	}
}

template<typename T>
void print(vector<vector<T>> &x) {
	int n = x.size();
	rep(i,n) {
		rep(j,x[i].size()) {
			cout << x[i][j] << " ";
		}
		cout << endl;
	}
}

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(int argc, char const *argv[]) {
	int n; cin>>n;
	vector<int> d;
	map<int,int> mp;
	rep(i,n) {
		int a; scanf("%d",&a);
		mp[a]++;
		if (mp[a]>=2) continue;
		d.push_back(a);
	}

	n = d.size();
	int ans = 0;
	for (int mask = 0; mask < (1<<n); ++mask) {
		int tmp = INF;
		vector<int> a;
		rep(j,n) {
			int x = d[j];
			if (mask&(1<<j) && x!=0) x = 24-x;
			a.push_back(x);
		}
		a.push_back(0);
		for (auto &&e: mp) {
			if (e.second>=2) rep(l,e.second-1) a.push_back(e.first);
		}    
		sort(a.begin(), a.end());

		rep(j,a.size()-1) {
			if (j == 0) tmp = min(a[j+1],24-a[j+1]);
			else chmin(tmp,abs(a[j]-a[j+1]));
		}
		for (int j = 1; j < a.size(); ++j) chmin(tmp,min(a[j],24-a[j]));
		chmax(ans,tmp);
	}

	cout << ans << endl;
	return 0;
}