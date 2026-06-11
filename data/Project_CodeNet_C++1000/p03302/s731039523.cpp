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
#define ps(x) cout<<fixed<<setprecision(25)<<x<<endl;
#define pu(x) cout<<x;
#define re(i,a,b) for(i=a;i<=b;i++);
#define pb push_back
#define lb lower_bound
#define ub upper_bound
 
ll rui(ll abc,ll bed){
	//aのb乗を計算する
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
ll n,m,sum,num;
ll a,b,c,d,e,ans;
ll x[500005],y[500005],z[500005];
ll ma,mi;
char s[100005],t[100005];
double aa;

int main(){
	cin>>a>>b;
	if(a+b==15)p("+");
	if(a*b==15)p("*");
	if(a+b!=15 && a*b!=15)p("x");

	return 0;
}