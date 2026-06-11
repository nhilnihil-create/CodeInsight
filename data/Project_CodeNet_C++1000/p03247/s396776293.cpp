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
long long int mod = 1000000007;
 
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
char dir[] = "RULD";
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
ll n,m,num;
ll a,b,c,d,e,f,g,h,w;
ll x[800005],y[800005],z[900005];
char s[500005];
ll len[500];
bool dame;


int main(){	
	cin>>n;
	for(i=0;i<n;i++){
		cin>>x[i]>>y[i];
		//if(abs(x[i]) >= 11 || abs(y[i]) >= 11){
		//	return 0;
		//}
	}
	len[31] = 1;
	for(i=30;i>=0;i--){
		len[i] = len[i+1] * 2;
	}

	a = abs(x[0]) + abs(y[0]);
	for(i=0;i<n;i++){
		if((x[i] + y[i] - a) % 2 == 1){
			dame = true;
		}
	}
	if(dame){
		p(-1);
		return 0;
	}
	if(a%2==0){
		for(i=0;i<n;i++){
			x[i] += 1;
		}
		p(33);
		for(i=0;i<32;i++){
			pe(len[i]);
		}
		p(1);
	}else{
		p(32);
		for(i=0;i<32;i++){
			pe(len[i]);
		}
		el;
	}
	for(i=0;i<n;i++){
		ll posx = 0;
		ll posy = 0;
		for(j=0;j<32;j++){
			ll knum = -1;
			ll ksum = INF;
			ll lenx,leny;
			for(k=0;k<4;k++){
				//どの方向に使うべきかを決める
				lenx = dx[k] * len[j];
				leny = dy[k] * len[j];
				if(ksum > abs(x[i] - (posx + lenx)) + abs(y[i] - (posy + leny))){
					ksum = abs(x[i] - (posx + lenx)) + abs(y[i] - (posy + leny));
					knum = k;
				}
			}
			posx += dx[knum] * len[j];
			posy += dy[knum] * len[j];
			//pe(knum);pe(posx);p(posy);
			pu(dir[knum]);
		}
		if(a%2==0){
			pu("L");
		}
		//pe(posx);p(posy);
		el;
	}
	return 0;
}