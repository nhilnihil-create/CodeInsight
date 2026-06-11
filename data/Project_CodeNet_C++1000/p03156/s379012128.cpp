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
//(a+b-1)/b


signed main(){
	int n; cin>>n;
	int a,b; cin>>a>>b;
	vl vec(n);
	rep(i,0,n)cin>>vec[i];
	sort(all(vec));
	int i=upper_bound(all(vec),a)-vec.begin();
	int j=vec.end()-lower_bound(all(vec),b+1);
	cout<<min({n-i-j,i,j})<<endl;
	
	return 0;
}