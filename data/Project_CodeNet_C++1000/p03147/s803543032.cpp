#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define all(x) x.begin(),x.end()
#define rep(i,j,n) for (long long i = j; i < (long long)(n); i++)
#define _GLIBCXX_DEBUG
#define MOD 1000000007
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//name[i][j]-> vvl name(i,vl(j))
//map<int,int>mp
//余りを切り上げる =>  (a + b - 1) / b 

signed main(){
	int n; cin>>n;
	vi a(n),b(n+1,0);
	a.push_back(0);
	int m=0;
	rep(i,0,n){
		cin>>a[i];
		chmax(m,a[i]);
	}
	int ans=0;
	rep(i,0,m){
		if(a==b)break;
		int cnt=0;
		rep(j,0,n){
			if(a[j]==0)continue;
			if(a[j+1]==0){
				cnt++;
			}
			//if(a[i])a[i]--;
		}
		rep(i,0,n)a[i]=max(a[i]-1,0);
		ans+=cnt;
		//cout<<"  cnt: "<<cnt<<endl;
	//	rep(j,0,n)cout<<a[j]<<" ";
	}
	cout<<ans<<endl;
	
	
	
	return 0;
}