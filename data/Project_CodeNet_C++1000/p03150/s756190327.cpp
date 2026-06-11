#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define rev(i,n) for(int i=n-1;i>=0;i--)
#define all(v) v.begin(),v.end()
#define P pair<int,int>
#define len(s) (int)s.size()

template<class T> inline bool chmin(T &a, T b){
	if(a>b){a=b;return true;}
	return false;
}
template<class T> inline bool chmax(T &a, T b){
	if(a<b){a=b;return true;}
	return false;
}
template<class T>inline int cmp(vector<T>&v,T &a){
	return lower_bound(all(v),a)-v.begin();
}
constexpr int mod = 1e9+7;
constexpr int inf = 3e18;


signed main(){
	string S;
	cin>>S;
	rep(i,8){
		if(S.substr(0,i)+S.substr(len(S)-(7-i))=="keyence"){
			cout<<"YES\n";return 0;
		}
	}
	cout<<"NO\n";
}
