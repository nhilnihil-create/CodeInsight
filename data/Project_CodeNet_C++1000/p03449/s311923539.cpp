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
	vi a(n+2),b(n+2);
	a[0]=0; a[n+1]=0; 
	b[0]=0; a[n+1]=0;
	rep(i,1,n+1){
		cin>>a[i];
		a[i]+=a[i-1];
	}
	rep(i,1,n+1){
		cin>>b[i];
	}
	for(int i=n;i>=1;i--){
		b[i]+=b[i+1];
	}
	int m;
	int ans=0;
	rep(i,1,n+1){
		if(ans<a[i]+b[i]){
			ans=a[i]+b[i];
			m=i;
		}
	}
	cout<<ans<<endl;
	
	return 0;
}