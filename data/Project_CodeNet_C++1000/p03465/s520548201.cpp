#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define P pair<int,int>
#define int long long
#define mod (int)(1e9+7)
#define inf (int)(3e18)
#define all(v) v.begin(),v.end()
using namespace std;

template<class T> inline void chmax(T& a, T b) { a = std::max(a, b); }
template<class T> inline void chmin(T& a, T b) { a = std::min(a, b); }

int n,a[2005];
bitset<4000005>bit;
signed main() {
	cin>>n;
	int sum=0;
	rep(i,n){
		cin>>a[i];
		sum+=a[i];
	}
	bit.set(0);
	rep(i,n){
		bit|=bit<<a[i];
	}
	for(int i=(sum+1)/2;;i++){
		if(bit[i]){
			cout<<i<<endl;
			return 0;
		}
	}
}
