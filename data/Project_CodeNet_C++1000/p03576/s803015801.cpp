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
	int n,k;cin >> n >> k;
	vector<ll> x(n),y(n);
	rep(i,n) cin >> x.at(i) >> y.at(i);
	ll ans = 4e18;
	rep(x1,n){
		for(int x2 = x1 + 1; x2 < n; x2++){
			rep(y1,n){
				for(int y2 = y1 + 1; y2 < n; y2++){
					ll xmin = min(x.at(x1), x.at(x2)), xmax = max(x.at(x1), x.at(x2)), ymin = min(y.at(y1), y.at(y2)), ymax = max(y.at(y1), y.at(y2));
					int cnt = 0;
					rep(i,n){
						if(x.at(i) >= xmin && x.at(i) <= xmax && y.at(i) >= ymin && y.at(i) <= ymax) cnt++;
					}
					if(cnt >= k) ans = min(ans, (xmax - xmin) * (ymax - ymin));
				}
			}
		}
	}
	cout << ans << endl;
}
