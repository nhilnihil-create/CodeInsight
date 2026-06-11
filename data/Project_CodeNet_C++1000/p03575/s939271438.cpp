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
using pi = pair<int,int>;

signed main(){
	int n,m; cin>>n>>m;
	vector<pi> vec(m);
	vvi g(n,vi(0));
	rep(i,0,m){
		int a,b; cin>>a>>b;
		--a; --b;
		vec[i]=make_pair(a,b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	ll ans=0;
	rep(i,0,m){
		int a=vec[i].first,b=vec[i].second;
		vector<bool> seen(n);
		queue<int> q;
		int cnt=0;
		q.push(0);
		seen[0]=true;
		while(!q.empty()){
			cnt++;
			int k=q.front(); q.pop();
			for(auto c:g[k]){
				if(k==a && c==b)continue;
				if(k==b && c==a)continue;
				if(seen[c])continue;
				seen[c]=true;
				q.push(c);
			}
		}
		if(cnt!=n)ans++;
	}
	cout<<ans<<endl;
	return 0;
}