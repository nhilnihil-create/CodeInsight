//daddy's back in town, back to rolling the damn hash yoooo babeeeeees//
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define clock (clock() * 1000.0 / CLOCKS_PER_SEC)
#define dbg(x) cout << #x << '=' << x << '\n';
#define ll long long
#define x first
#define y second
#define pi pair <int, int>
#define vi vector <int>
#define L nod<<1
#define R ((nod<<1)|1)
#define int ll
const ll mod = 998244353;
int n, c, a[100010], v[100010], pr[100010], s[100010], ans;

int32_t main(){
	ios_base :: sync_with_stdio(0); cin.tie(); cout.tie();
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	cin>>n>>c;
	for(int i=1; i<=n; i++) cin>>a[i]>>v[i];
	for(int i=n; i>=1; i--) s[i]=s[i+1]+v[i];

	for(int i=1; i<=n; i++) pr[i]=pr[i-1]+v[i];
	for(int i=1; i<=n; i++) pr[i]-=a[i], pr[i]=max(pr[i], pr[i-1]);
	ans=pr[n];
	//cout<<pr[n]<<endl;
	for(int b=1; b<=n; b++) ans=max(ans, s[b]+pr[b-1]-2*(c-a[b]/*haha lol*/));
	//cout<<s[2]<<" "<<pr[1]<<" "<<a[2]<<endl;

	for(int i=1; i<=n; i++) pr[i]=pr[i-1]+v[i];
	for(int i=1; i<=n; i++) pr[i]-=2*a[i], pr[i]=max(pr[i], pr[i-1]);
	ans=max(ans, pr[n]);
	for(int b=1; b<=n; b++) ans=max(ans, s[b]+pr[b-1]-(c-a[b]/*haha lol*/));
	cout<<ans;
}