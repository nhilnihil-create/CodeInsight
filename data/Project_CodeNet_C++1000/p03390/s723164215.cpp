#include <iostream>
#include <climits>
#include <stack>
#include <queue>
#include <string>
#include <random>
#include <utility>
#include <cmath>
#include <set>
#include <map>
#include <math.h>
#include <string.h>
#include <iomanip>
#include <stdlib.h>
#include <algorithm>
#include <vector>
 
using namespace std;
typedef long long ll;
 
 
typedef pair<ll,ll> P;
long long int INF = 1e18;
double Pi = 3.141592653589;
const int mod = 1000000007;
// memset(a,0,sizeof(a)); →全部０にする
 
vector<int> G[100005];
std::vector<P> tree[100010];
 
int dx[8]={1,0,-1,0,1,1,-1,-1};
int dy[8]={0,1,0,-1,1,-1,-1,1};
 
ll i,j,k;
ll a[500],b[500],c=0;
ll n,m,q;
ll ans;
 
int main(){
 
	cin>>q;
 
	for(i=0;i<q;i++){
		cin>>a[i]>>b[i];
	}
	for(i=0;i<q;i++){
		ans=0;
		if(a[i]>b[i])swap(a[i],b[i]);
		ll r=sqrt((b[i]*a[i]-1)*1.0000000);
		c=r;
		for(j=c-2;j<=c+2;j++){
			if(j*j<b[i]*a[i])r=j;
		}
		if(r*r+r>b[i]*a[i]-1){
			ans=2*r-2;
		}else{
			ans=2*r-1;
		}
		if(b[i]==a[i])ans=2*a[i]-2;
		cout<<ans<<endl;
	}
	return 0;
}