#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
template <class T> inline bool chmin(T &a, T b) {if (a > b){a = b;return true;}return false;}
template <class T> inline bool chmax(T &a, T b) {if (a < b){a = b;return true;}return false;}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;cin>>n;
	vector<int> a;
	ll sum = 0;
	for(int i=1;i<=n;i++) {
		int t;cin>>t;
		a.emplace_back(t-i);
	}
	sort(all(a));
	ll tmp = a[n/2];
	ll ans = 0;
	for(auto t : a){
		ans += abs(t-tmp);
	}
	cout<<ans<<endl;
}