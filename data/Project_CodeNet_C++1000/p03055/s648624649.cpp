#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp(a) setprecision(a)<<fixed
#define ss second
#define fori(v) for(ll i=0; i<v; i++)
#define forj(v) for(ll j=0; j<v; j++)
#define fork(v) for(ll k=0; k<v; k++)
#define forl(v) for(ll l=0; l<v; l++)
#define fort(v) for(ll t=0; t<v; t++)
#define forz(v) for(ll z=0; z<v; z++)
#define forx(v) for(ll x=0; x<v; x++)
#define fory(v) for(ll y=0; y<v; y++)
#define ll long long 
#define double long double
#define MAX 200100
#define pb(a) push_back(a)
const ll INF = 0x3f3f3f3f;
const ll inf = INF;
ll modulo = pow(10,9)+7;
vector<int> g[MAX];
int Mx[MAX];
multiset<int> dist;
int mx = 0;
void dfs(int hd, int pr){
	int all[2] = {0,0};
	fori(g[hd].size()){
		int hr = g[hd][i];
		if(hr == pr)
			continue;
		dfs(hr, hd);
		if(Mx[hr] + 1 > all[0])
			all[1] = all[0], all[0] = Mx[hr] + 1;
		else if(Mx[hr] + 1 > all[1])
			all[1] = Mx[hr] + 1;
	}
	mx = max(all[0] + all[1], mx);
	Mx[hd] = all[0];
}
void deal(){
	int n;
	cin>>n;
	fori(n-1){
		int a,b;
		cin>>a>>b;
		--a,--b;
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs(0, -1);
	if(mx%3 == 1)
		cout<<"Second";
	else
		cout<<"First";
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}

























