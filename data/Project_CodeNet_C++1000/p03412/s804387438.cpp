#include <bits/stdc++.h>
#define FI first
#define SE second
#define PB push_back
#define ll long long
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define ROF(i,a,b) for(int i=b-1;i>=a;i--)
#define YES(i) cout<<(i?"YES":"NO")<<endl
#define Yes(i) cout<<(i?"Yes":"No")<<endl
#define co(i) cout<<(i)<<endl
#define fcout cout<<fixed<<setprecision(10)
#define uni(i) i.erase(unique(i.begin(), i.end()), i.end());
#define all(i) i.begin(),i.end()
#define pint pair<int, int>
#define vint vector<int>
using namespace std;

const int INF=1e9+7;
const ll LINF=1e18;
const int MOD=1e9+7;
//const int MOD=998244353;

int n;
int a[200001],b[200001];
int main(){
	cin>>n;
	FOR(i,0,n) cin>>a[i];
	FOR(i,0,n) cin>>b[i];
	int ans=0;
	FOR(j,0,30){
		int c=0;
		FOR(i,0,n) c^=(a[i]>>j);
		FOR(i,0,n) c^=(b[i]>>j);
		c&=1;
		c&=n;
		vint v;
		FOR(i,0,n) v.push_back(a[i]%(1<<j));
		sort(all(v));
		int k=0;
		FOR(i,0,n){
			k+=v.end()-lower_bound(all(v),(1<<j)-b[i]%(1<<j));
		}
		//cout<<k<<" "<<c<<endl;
		(c^=k)&=1;
		ans+=c<<j;
	}
	//cout<<endl;
	co(ans);
}
