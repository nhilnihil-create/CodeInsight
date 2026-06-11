#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
int main(){
	cout << fixed << setprecision(10);
	int h,w,d;
	cin >> h >> w >> d;
	map<int,pair<int,int>> mpi;
	rep(i,h) rep(j,w){
		int x;
		cin >> x;
		mpi[x] = {i+1,j+1};
	}
	int mp[h*w+1];
	for(int i=1;i<=h*w;i++){
		if(i<=d){
			mp[i] = 0;
		}else{
			mp[i] = mp[i-d] + abs(mpi[i].first-mpi[i-d].first) + abs(mpi[i].second-mpi[i-d].second);
		}
	}
	int q;
	cin >> q;
	vector<int> ans;
	rep(i,q){
		int l,r;
		cin >> l >> r;
		ans.push_back(mp[r]-mp[l]);
	}
	for(auto u : ans){
		cout << u << endl;
	}
	return 0;
}