#include <iostream>
#include <cassert>
#include <climits>
#include <bitset>
#include <stack>
#include <queue>
#include <iomanip>
#include <limits>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string.h>
 
using namespace std;
typedef long long ll;
 
typedef pair<ll,ll> P;
long long int INF = 1e18;
double Pi = 3.1415926535897932384626;
long long int mod = 998244353;
 
vector<ll> G[500005];
vector<P> tree[500010];
priority_queue <ll> pql;
priority_queue <P> pqp;
//big priority queue
priority_queue <ll,vector<ll>,greater<ll> > pqls;
priority_queue <P,vector<P>,greater<P> > pqps;
//small priority queue
//top pop

int dx[8]={1,0,-1,0,1,1,-1,-1};
int dy[8]={0,1,0,-1,1,-1,-1,1};
//↓,→,↑,←
 
#define p(x) cout<<x<<endl;
#define el cout<<endl;
#define pe(x) cout<<x<<" ";
#define ps(x) cout<<fixed<<setprecision(25)<<x<<endl;
#define pu(x) cout<<x;
#define re(i,a,b) for(i=a;i<=b;i++);
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define deba(x) cout<< #x << " = " << x <<endl

ll rui(ll abc,ll bed){
	//abcのbed乗を計算する
	if(bed==0){return 1;}
	else{
		ll ced = rui(abc,bed/2);
		ced *= ced;
		ced %= mod;
		if(bed%2==1){ced*=abc; ced%=mod;}
		return ced;
	}
} 

ll i,j,k,ii,jj;
ll n,m,num,sumxor,sum,ans;
ll a,b,c,d,e,f,g,h,w,v;
ll x[800005],y[800005],z[900005];
char s[500005];
ll dp[800005];
bool deleted[500005];
bool update;


int main(){	
	cin >> n >> m;
	cin >> s;
	d = n;
	for(i=0;i<m;i++){
		cin >> a >> b;
		G[a].pb(b);
		G[b].pb(a);
	}
	//両方がない点を探すよ
	for(i=1;i<=n;i++){
		a = 0;
		b = 0;
		for(j=0;j<G[i].size();j++){
			if(s[G[i][j]-1]=='A')a=1;
			if(s[G[i][j]-1]=='B')b=1;
		}
		if(a*b==0){
			pql.push(i);
			deleted[i] = true;
			d--;
			//i番目の頂点には両方ないよ
		}
	}
	update = true;
	while(!pql.empty() && d>=0){
		ll v = pql.top();
		pql.pop();
		for(i=0;i<G[v].size();i++){
			if(deleted[G[v][i]])continue;
			//v番目の頂点につながってる頂点を全部見る
			c = G[v][i];
			a = 0;
			b = 0;
			for(j=0;j<G[c].size();j++){
				if(deleted[G[c][j]])continue;	
				if(s[G[c][j]-1]=='A')a = 1;
				if(s[G[c][j]-1]=='B')b = 1;
			}
			if(a*b==0){
				pql.push(c);
				deleted[c] = true;
				d--;
			}
		}
	}

	if(d<=0){
		p("No");
	}else{
		p("Yes");
	}

		
	return 0;
}