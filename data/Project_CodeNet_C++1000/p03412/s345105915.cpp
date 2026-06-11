#include <bits/stdc++.h>
#define rep(a,b) for(int a=0; a<b; ++a)
#define ran(a,b) for(auto &a:b)
#define all(v) v.begin(),v.end()
using namespace std;

template<typename T>
using pq = priority_queue<T>;
template<typename T>
using rpq = priority_queue<T,vector<T>,greater<T>>;
template<typename T>
using vec = vector<T>;

using ll = long long;
using pi = pair<int,int>;
using ti = tuple<int,int,int>;
using tup = tuple<string,int,int>;

ll MOD=1000000007;

int main(){
	int N; cin>>N;
	vec<ll> a(N),b(N);
	rep(i,N) cin>>a[i];
	rep(i,N) cin>>b[i];
	int ans=0;
	for(int di=29; di>=0; --di){
		ll hi=(1<<(di+1)),lo=(1<<di);
		rep(i,N) a[i]%=hi,b[i]%=hi;
		sort(all(b));
		int cnt=0;
		ran(i,a){
			int add=0;
			if(lo-i>=0){
				add+=lower_bound(all(b),2*lo-i)-lower_bound(all(b),  lo-i);
			}
			else{
				add+=lower_bound(all(b),2*lo-i)-b.begin();
				add+=lower_bound(all(b),2*lo)-lower_bound(all(b),3*lo-i);
			}
			cnt+=add;
		}
		if(cnt&1) ans+=lo;
	}
	//ran(i,k) cout<<i<<" ";
	cout<<ans<<endl;
}