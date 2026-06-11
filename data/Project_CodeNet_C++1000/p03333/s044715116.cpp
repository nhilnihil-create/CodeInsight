#include <iostream>
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
double Pi = 3.141592653589;
const int mod = 1000000007;
// memset(a,0,sizeof(a)); →全部０にする
 
vector<ll> G[100005];
std::vector<P> tree[100010];
 
int dx[8]={1,0,-1,0,1,1,-1,-1};
int dy[8]={0,1,0,-1,1,-1,-1,1};
 
#define p(x) cout<<x<<endl;
#define el cout<<endl;
#define pe(x) cout<<x<<" ";
#define re(i,a,b) for(i=a;i<=b;i++);
#define pb push_back
 
ll i,j,k,ii,jj;
ll n,m,sum,num;
ll a,b,c,d,e,ans=1;
ll x[500005],y[100005],z[100005];
bool p[500005]; 
 
int main(){
	cin>>n;
	for(i=0;i<n;i++){
		cin>>x[i]>>y[i];
	}
	sort(x,x+n);
	reverse(x,x+n);
	sort(y,y+n);
	ll res=0,tmp=0;
	for(i=0;i<n/2+1;i++){
		tmp += x[i];
		res = max(res,tmp);
		//pe(tmp);
		tmp -= y[i];
		res = max(res,tmp);
		//pe(tmp);
	}
	el;
	tmp=0;
	for(i=0;i<n/2+1;i++){
		tmp -= y[i];
		//pe(tmp);
		res = max(res,tmp);
		tmp += x[i];
		//pe(tmp);
		res = max(res,tmp);
	}
	el;
	p(2*res);
	return 0;
}