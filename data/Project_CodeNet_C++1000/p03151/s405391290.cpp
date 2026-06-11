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
	ll asum=0,bsum=0;
	vl a(n),b(n);
	rep(i,0,n)cin>>a[i],asum+=a[i];
	rep(i,0,n)cin>>b[i],bsum+=b[i];
	if(asum<bsum){
		cout<<-1<<endl;
		return 0;
	}
	vl s(0),t(0);
	ll ans=0;
	// sは必要な方
	ll cnt=0;
	// tは余ってる方
	rep(i,0,n){
		if(b[i]>a[i]){
			cnt+=b[i]-a[i];
			ans++;
		}
		else if(b[i]!=a[i]){
			t.push_back(a[i]-b[i]);
		}
	}
	sort(all(t));
	ll j=t.size();
	if(cnt>0){
		for(int i=t.size()-1;i>=0;--i){
			ans++;
			if(cnt<=t[i])break;
			else cnt-=t[i];
		}
	}
	cout<<ans<<endl;
	return 0;
}