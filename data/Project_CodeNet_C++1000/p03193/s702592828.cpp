#include <bits/stdc++.h>
#define For(i,a,b) for(int i=a;i<=b;i++)
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define MOD (ll)(1e9+7)
#define INF 1e17
#define int ll
#define EPS (1e-6)
using namespace std;
using ll=long long;
using pii=pair<int,int>;

int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }
int lcm(int a,int b) { return a/gcd(a,b)*b; }

int fpow(int b,int p)
{
	if(p==0) return 1;
	int h=fpow(b,p/2);
	if(p%2) return h*b%MOD*h%MOD;
	return h*h%MOD;
}

bool cmp(pii a,pii b){
	return a.S<b.S;
}

int find(vector<int> &dp,int t){
	int hi=sz(dp)-1,lo=-1;
	while(hi-lo>1){
		int m=(hi+lo)/2;
		if(dp[m]<=t) lo=m;
		else hi=m;
	}
	return hi;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n,h,w; cin>>n>>h>>w;
	int x,y,cnt=0;
	while(n--){
		cin>>x>>y;
		if(x>=h && y>=w) cnt++;
	}
	cout<<cnt<<"\n";
}

























