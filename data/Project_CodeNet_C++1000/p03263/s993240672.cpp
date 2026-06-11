#include <algorithm>
#include <cmath>
#include <vector>
#include <functional>
#include <cstdlib>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <ctype.h>
#include <climits>
#include <queue>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < (ll)(n); ++i)
#define FOR(i, a, b) for(ll i=(a); i < (ll)(b); ++i)
template<class T> inline bool chmax(T& a, T b) { if(a < b){ a=b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if(a > b){ a=b; return 1; } return 0;}

int main(){
	int h,w;
	cin >> h >> w;
	vector<vector<int>> a(h,vector<int>(w));
	REP(i,h) REP(j,w) cin >> a[i][j];
	
	vector<vector<int>> ans;
	REP(i,h){
		if(i%2==0){
			for(int j=0; j<w; j++){
				vector<int> change(4);
				int nexti, nextj;
				if(a[i][j]%2==1){
					change[0]=i+1;
					change[1]=j+1;
					
					if(j < w-1){
						nexti=i;
						nextj=j+1;
					}else if(i < h-1){
						nexti=i+1;
						nextj=j;
					}else{
						continue;
					}
					change[2]=nexti+1;
					change[3]=nextj+1;
					
					a[nexti][nextj]++;
					ans.push_back(change);
				} 
			}
		}else{
			for(int j=w-1; j>=0; j--){
				vector<int> change(4);
				int nexti, nextj;
				if(a[i][j]%2==1){
					change[0]=i+1;
					change[1]=j+1;
					
					if(j > 0){
						nexti=i;
						nextj=j-1;
					}else if(i < h-1){
						nexti=i+1;
						nextj=j;
					}else{
						continue;
					}
					change[2]=nexti+1;
					change[3]=nextj+1;
					
					a[nexti][nextj]++;
					ans.push_back(change);
				} 
			}
		}
	}
	
	cout << ans.size() << endl;
	for(auto x:ans){
		REP(i,4){
			if(i!=0) cout << " ";
			cout << x[i];
		}
		cout << endl;
	}
	
	return 0;
}