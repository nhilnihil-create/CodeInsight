#include <iostream>
#include <climits>
#include <stack>
#include <queue>
#include <string>
#include <random>
#include <utility>
#include <cmath>
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
 
struct edge{int to,cost;};
vector<int> G[100005];
 
int dx[8]={1,0,-1,0,1,1,-1,-1};
int dy[8]={0,1,0,-1,1,-1,-1,1};
 
std::vector<P> tree[100010];
ll i,j;

ll n,m,ans=0;
ll a,b,c,k,num=0;
ll d[500005];

int main(){
	cin>>n>>a>>b;
	memset(d,0,sizeof(d));
	c = a*b;
	if((a+b>n+1) || (a*b<n)){
		cout<<-1;
	}else if(a!=1){
		d[1]=b;
		n-=b;

		for(i=2;i<=a;i++){
			d[i]=n/(a-1);
		}
		for(i=2;i<=1+n%(a-1);i++){
			d[i]++;
		}
		for(i=1;i<=a;i++){
			num += d[i];
			for(j=1;j<=d[i];j++){
				printf("%d ",num-j+1);
			}
		}
	}else{
		for(i=n;i>=1;i--){
			printf("%d ",i);
		}
	}
	cout<<endl;
	return 0;
}