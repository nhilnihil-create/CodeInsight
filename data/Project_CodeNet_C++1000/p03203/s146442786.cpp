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
const int MOD=1e9+7;
//const int MOD=998244353;

int main(){
	int h,w,n; cin>>h>>w>>n;
	vector<pint> v;
	FOR(i,0,n){
		int x,y; cin>>x>>y;
		x--; y--;
		v.PB(pint(x,y));
	}
	int k[200001];
	FOR(i,0,h){
		k[i]=min(w,h-i);
	}
	FOR(i,0,n){
		int x=v[i].first,y=v[i].second;
		if(x-y>=0){
			k[x-y]=min(k[x-y],y);
		}
	}
	int ans=h;
	FOR(i,0,n){
		int x=v[i].first,y=v[i].second;
		x--;
		if(x-y>=0){
			if(y<k[x-y])ans=min(ans,x+1);
		}
	}
	co(ans);
}
