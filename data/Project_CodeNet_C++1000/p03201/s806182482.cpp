#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<(n);++i)
constexpr int mod=1000000007;
constexpr int mod1=998244353;
vector<int> dx={0,1,0,-1},dy={-1,0,1,0};
bool inside(int y,int x,int h,int w){
	if(y<h && y>=0 && x<w && x>=0) return true;
	return false;
}





int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;cin >> n;
	vector<ll> a(n);
	map<ll,int> m;
	rep(i,n){
		cin >> a.at(i);
		m[a.at(i)]++;
	}
	sort(a.rbegin(),a.rend());
	ll t = 2;
	while(t <= a.at(0)){
		t <<= 1;
	}
	int ans = 0;
	rep(i,n){
		if(m[a.at(i)] == 0) continue;
		while(t / 2 > a.at(i)) t >>= 1;
		if(a.at(i) == t - a.at(i)){
			if(m[a.at(i)] > 1){
				ans++;
				m[a.at(i)] -= 2;
			}
		}
		else if(m[t - a.at(i)] > 0){
			ans++;
			m[a.at(i)]--;
			m[t - a.at(i)]--;
		}
	}
	cout << ans << endl;
}