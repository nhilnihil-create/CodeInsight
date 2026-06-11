#include <bits/stdc++.h>
using namespace std;
 
//#define kk
#define int long long
#define FOR(a, b) for(int i=a; i<=b; i++)
#define REP(i, a, b) for(int i=a; i<=b; i++)
#define ff first
#define ss second
#define ll long long
#define inf 1000000000
#define pb push_back
#define mod 1000000007
 
const ll INF=1e18+5;
const int maxN=2e5+5;
typedef pair<int, int> pi;
 
pair<int, pi> arr[maxN];
int st[4*maxN];

int query(int si, int ss, int se, int qs, int qe){
	if(qs>se || qe<ss) return INT_MIN;
	
	if(qs<=ss && se<=qe) return st[si];
	
	int mid=ss+(se-ss)/2;
	
	int l=query(2*si, ss, mid, qs, qe);
	int r=query(2*si+1, mid+1, se, qs, qe);
	
	return max(l, r);
}

void update(int si, int ss, int se, int qi, int val){
	if(ss==se){
		st[si]=val;
		return;
	}
	
	int mid=ss+(se-ss)/2;
	
	if(qi<=mid) update(2*si, ss, mid, qi, val);
	else update(2*si+1, mid+1, se, qi, val);
	
	st[si]=max(st[2*si], st[2*si+1]);
}

void solve(){
	int n, x;
	cin>>n;
	
	FOR(1, n){
		cin>>x;
		arr[i].ff=x;
	}
	
	FOR(1, n){
		cin>>x;
		arr[i].ss.ff=x;
		arr[i].ss.ss=i;
	}
	
	
	sort(arr+1, arr+n+1, [&](pair<int, pi> a, pair<int, pi> b){
		return a.ff>b.ff;
		});
	
	
	FOR(1, n){
		int index=arr[i].ss.ss;
		int val=query(1, 1, n, index, n);
		val+=arr[i].ss.ff;
		update(1, 1, n, index, val);
	}
	
	int ans=-INF;
	
	FOR(1, n){
		ans=max(ans, st[i]);
	}
	
	cout<<ans<<endl;
}
 
 
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cout<<fixed<<setprecision(6);
	
	#ifdef kk
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	int T=1;
	//cin>>T;
	
	while(T--){		
		solve();
	}
}
