#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int h, w;
	cin >> h >> w;
	vector<vector<int>> a(h, vector<int>(w));
	rep(i,h)rep(j,w) cin >> a[i][j];
	vector<pair<P, P>> ans;
	rep(i,h){
		if(i%2 == 0){
			rep(j,w){
				if(j+1 < w){
					if(a[i][j]%2 == 1){
						a[i][j]--;
						a[i][j+1]++;
						ans.push_back(make_pair(P(i+1,j+1), P(i+1,j+2)));
					}
				}
				else{
					if(a[i][j]%2 == 1 && i+1 < h){
						a[i][j]--;
						a[i+1][j]++;
						ans.push_back(make_pair(P(i+1,j+1), P(i+2,j+1)));
					}
				}
			}
		}
		else{
			for(int j = w-1; j >= 0; --j){
				if(j-1 >= 0){
					if(a[i][j]%2 == 1){
						a[i][j]--;
						a[i][j-1]++;
						ans.push_back(make_pair(P(i+1,j+1), P(i+1,j)));
					}
				}
				else{
					if(a[i][j]%2 == 1 && i+1 < h){
						a[i][j]--;
						a[i+1][j]++;
						ans.push_back(make_pair(P(i+1,j+1), P(i+2,j+1)));
					}
				}
			}
		}
	}
	cout << ans.size() << endl;
	for(auto p : ans){
		cout << p.first.first << " " << p.first.second << " " << p.second.first << " " << p.second.second << endl;
	}
	return 0;
}