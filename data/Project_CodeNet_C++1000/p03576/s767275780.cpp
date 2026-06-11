#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
int n,k;
vector<pi>spots;
int arr[55][55];
int psum[55][55];
vector<ll>y_index;
vector<ll>x_index;
vector<ll>::iterator it;
long long minarea = numeric_limits<long long>::max();
void solve(){
	for(int y_start=0; y_start<y_index.size(); y_start++){
		for(int y_fin = y_start+1; y_fin<y_index.size(); y_fin++){
			for(int x_start = 0; x_start<x_index.size(); x_start++){
				for(int x_fin = x_start+1; x_fin<x_index.size(); x_fin++){
					int num = psum[y_fin+1][x_fin+1]-psum[y_start][x_fin+1]-psum[y_fin+1][x_start]+psum[y_start][x_start];
					if(num>=k){
						long long x = x_index[x_fin]-x_index[x_start];
						long long y = y_index[y_fin]-y_index[y_start];
						minarea = min(minarea,x*y);
					}
				} 
			}
		}
	}
}
int main(){
	cin>>n>>k;
	for(int i=0; i<n; i++){
		long long x,y;
		cin>>x>>y;
		spots.push_back(pi(y,x));
		x_index.push_back(x);
		y_index.push_back(y);
	}
	sort(all(y_index));
	sort(all(x_index));
	y_index.erase(unique(all(y_index)),y_index.end());
	x_index.erase(unique(all(x_index)),x_index.end());
	for(int i=0; i<spots.size(); i++){
		int y = spots[i].first;
		int x = spots[i].second;
		it = lower_bound(all(y_index),y);
		int yindex = (int)(it-y_index.begin()+1);
		it = lower_bound(all(x_index),x);
		int xindex = (int)(it-x_index.begin()+1);
		arr[yindex][xindex]++;
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			psum[i][j] = arr[i][j];
			psum[i][j]+=psum[i][j-1];
		}
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++) psum[i][j]+=psum[i-1][j];
	}
	solve();
	cout<<minarea;
}