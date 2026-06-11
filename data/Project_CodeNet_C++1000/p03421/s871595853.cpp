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
#define pint pair<ll, ll>
#define vint vector<int>
using namespace std;

const int INF=1e9+7;
const ll LINF=1e18;
const int MOD=1e9+7;
//const int MOD=998244353;

vector<pint> v(300001);
int n; ll a,b;
int main(){
	cin>>n>>a>>b;
	if(a+b-1>n || a*b<n){
		co(-1);
		return 0;
	}
	ll k=10000000;
	int bb=b;
	FOR(i,0,n){
		if(i%a==0||n-i<=bb){
			if(i%a==0) bb--;
			v[i]=pint(k,i);
			k-=1000000;
		}else{
			v[i]=pint(v[i-1].first+1,i);
		}
	}
	sort(v.begin(),v.begin()+n);
	FOR(i,0,n){
		v[i].first=i;
		swap(v[i].first,v[i].second);
	}
	sort(v.begin(),v.begin()+n);
	FOR(i,0,n) cout<<v[i].second+1<<" \n"[i==n-1];
}
