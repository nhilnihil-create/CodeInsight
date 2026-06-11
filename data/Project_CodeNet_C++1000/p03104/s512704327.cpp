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

int f(int x){
	int res=0;
	rep(i,50){
		int j=x>>(i+1);j--;
		int cnt=(1ll<<i)*j;
		if(x>>i&1)cnt+=x%(1ll<<i)+1;
		if(cnt%2)res+=1ll<<i;
	}
	return res;
}
signed main(){
	int A,B;cin>>A>>B;
	cout<<(f(B)^f(A-1))<<"\n";
}
