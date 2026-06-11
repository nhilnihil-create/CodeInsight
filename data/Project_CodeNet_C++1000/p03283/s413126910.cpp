#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define print(A,x,n) rep(i,0,n){cout<<(i ? " ":"")<<A[i]x;}cout<<endl;
#define pprint(A,y,m,n) rep(j,0,m){print(A[j],y,n);}
const long mod=1e9+7;
const int size=2e5;
const int inf=1e9;
int main(){
	int N,M,Q;cin>>N>>M>>Q;
	vector<int> vec[N];
	rep(i,0,M){
		int l,r; cin>>l>>r; l--; r--;
		vec[l].push_back(r);
	}
	rep(i,0,N) sort(vec[i].begin(), vec[i].end());
	rep(i,0,Q){
		int p,q; cin>>p>>q; p--; q--;
		int res = 0;
		rep(j,p,q+1) res += upper_bound(vec[j].begin(), vec[j].end(), q) - vec[j].begin();
		cout<<res<<endl;
	}
}