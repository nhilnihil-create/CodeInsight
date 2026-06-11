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
 
vector<ll> G[100005];
vector<P> tree[100010];
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
ll dp[800005];


int main(){	
	cin>>n>>k;
	//if(n>=2001){
	//	return 0;
	//}
	for(i=0;i<n;i++){
		cin>>x[i];
		sum += x[i];
	}
	y[0] = x[0];
	for(i=1;i<n;i++){
		y[i] = y[i-1] + x[i];
	}
	dp[0] = 5;
	for(i=1;i<=2*n;i++){
		dp[i] = 2*i + 3;
	}
	ans = INF;
	for(j=1;j<=(n+5)/2;j++){
		sum = j * k;
		
		num = n-1;
		a = 0;
		while(num >= j){
			sum += dp[a] * (y[num] - y[num - j]);
			num -= j;
			a++;
		}
		sum += dp[a] * y[num];
		// J個ごとに和を取ろうぜ！
		if(sum < 0){
			sum = INF;
		}

		
		ans = min(ans,sum);
	}


	p(ans + k * n);
	
	return 0;
}