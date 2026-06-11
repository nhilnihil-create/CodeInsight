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
vector<ll> p[3];
bool dpx[100005],dpy[100005];
char s[100005];

int main(){
	cin>>s;
	cin>>a>>b;
	n=strlen(s);
	for(i=0;i<n;i++){
		if(s[i]=='F'){
			sum++;
		}else{
			p[num%2].pb(sum);
			if(num%2==0)a+=sum;
			if(num%2==1)b+=sum;
			sum=0;
			num++;
		}
	}
	p[num%2].pb(sum);
	if(num%2==0)a+=sum;
	if(num%2==1)b+=sum;
	sum=0;
	num++;
	dpx[p[0][0]]=true;
	for(i=1;i<p[0].size();i++){
		for(j=8000;j>=0;j--){
			if(dpx[j])dpx[j+p[0][i]]=true;
		}
	}
	dpy[0]=true;
	for(i=0;i<p[1].size();i++){
		for(j=8000;j>=0;j--){
			if(dpy[j])dpy[j+p[1][i]]=true;
		}
	}	
	if(dpx[a/2] && dpy[b/2] && a%2==0 && b%2==0 && a>=0 && b>=0){
		p("Yes");
	}else{
		p("No");
	}
	return 0;
}