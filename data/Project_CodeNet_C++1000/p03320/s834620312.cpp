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
ll a,b,c,d,e,ans=0;
ll x[100005],y[100005],z[100005];
float st;
stack <ll> ana;


ll digi(ll x){
	ll nono=0;
	while(x>0){
		nono += x%10;
		x/=10;
	}
	return nono;
}
int main(){
	cin>>n;
	x[1]=1;
	st=INF;
	for(i=1000000000000000;i>=1;i--){
		if((float)(i*1.000/digi(i))<=st){
			ana.push(i);
			st = i*1.000/digi(i);
		}
		if(i>=1000000000000 && i%10000000000 == 9999999999)i-=9999999999;
		if(i>=100000000 && i%1000000 == 999999)i-=999999;
		if(i>=1000000 && i%10000 == 9999)i-=9999;
		if(i>=10000 && i%100==99)i-=98;
	}
	while(n>0){
		p(ana.top());
		ana.pop();
		n--;
	}
	return 0;
}