#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <numeric>
#include <list>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define rep(i, n) for (int i = 0; i < n; i++)
#define rep1(i, n) for (int i = 1; i <= n; i++)
#define show(a, n) rep(i,n) {cout<<a[i]<<' ';} cout<<endl;

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<long long, long long> pll;

const int INF = 1 << 30;
const long long INFL = 1LL << 62;
const int MOD = 1000000007;
const int MAX = 100000;
const int N = 100000;

int main() {
	ll n,k;cin>>n>>k;
	ll t[N],d[N];
	rep(i,n) cin>>t[i]>>d[i];

	ll maxd[N+1];
	rep(i,n+1) maxd[i]=0;
	rep(i,n) maxd[t[i]]=max(d[i],maxd[t[i]]);

	pll p[N];
	rep(i,n) p[i]=pll(d[i],t[i]);

	vector<pll> vpll;
	rep(i,n+1) if(maxd[i]!=0) vpll.push_back(pll(maxd[i],i));

	sort(p,p+n,greater<pll>());
	sort(vpll.begin(),vpll.end(),greater<pll>());

	ll ans=0,ct=0;
	ll cnt[N+1];
	rep(i,n+1) cnt[i]=0;
	rep(i,k){
		ans+=p[i].first;
		cnt[p[i].second]++;
	}

	rep(i,n+1) if(cnt[i]>0) ct++;
	ans+=ct*ct;
	ll anst=ans;

	for(int i=k-1;i>=0;i--){
		if(cnt[p[i].second]<2) continue;
		if(ct>=vpll.size()) break;
		cnt[p[i].second]--;
		anst-=p[i].first;
		anst+=vpll[ct].first;
		anst+=2*ct+1;
		ct++;
		ans=max(anst,ans);
	}
	cout<<ans<<endl;
}
