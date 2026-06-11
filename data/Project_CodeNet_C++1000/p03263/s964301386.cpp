#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int a[505][505];

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int h, w;
	cin >> h >> w;
	rep(i,h)rep(j,w) cin >> a[i][j];
	vector<pair<P,P>> ans;
	for(int i = 0; i < h; ++i){
		if(i%2 == 0){
			for(int j = 0; j < w-1; ++j){
				if(a[i][j]%2 != 0){
					a[i][j]--;
					a[i][j+1]++;
					ans.emplace_back(P(i,j),P(i,j+1));
				}
			}
			if(i == h-1) continue;
			if(a[i][w-1]%2 != 0){
				a[i][w-1]--;
				a[i+1][w-1]++;
				ans.emplace_back(P(i,w-1),P(i+1,w-1));
			}
		}
		else{
			for(int j = w-1; j > 0; --j){
				if(a[i][j]%2 != 0){
					a[i][j]--;
					a[i][j-1]++;
					ans.emplace_back(P(i,j),P(i,j-1));
				}
			}
			if(i == h-1) continue;
			if(a[i][0]%2 != 0){
				a[i][0]--;
				a[i+1][0]++;
				ans.emplace_back(P(i,0),P(i+1,0));
			}
		}
	}
	cout << ans.size() << endl;
	for(auto p : ans){
		cout << p.first.first+1 << " " << p.first.second+1 << " ";
		cout << p.second.first+1 << " " << p.second.second+1 << endl;
	}
	return 0;
}