#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define rrep(i,j,n) for(int i=j;i<n;i++)
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
constexpr int mod = 998244353;
constexpr int inf = 3e18;

int N,H[105];
signed main(){
	cin>>N;
	rep(i,N)cin>>H[i];
	int ans=0;
	rep(i,101){
		rep(j,N){
			if(H[j]>=i&&H[j+1]<i)ans++;
		}
	}
	cout<<ans<<"\n";
}