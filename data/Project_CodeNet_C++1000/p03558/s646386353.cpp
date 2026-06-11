#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<deque>
#include<algorithm>
#include<cmath>
#include<climits>
#include<string>
#include<set>
#include<numeric>
#include<map>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i = 0;i<((int)(n));i++)
#define reg(i,a,b) for(int i = ((int)(a));i<=((int)(b));i++)
#define irep(i,n) for(int i = ((int)(n)-1);i>=0;i--)
#define ireg(i,a,b) for(int i = ((int)(b));i>=((int)(a));i--)
typedef long long ll;
typedef pair<ll, ll> mp;


int main(void){
	ll K,c[100010];
	cin>>K;
	rep(i,K){
		c[i]=1e9;
	}
	deque<ll> Q;
	Q.push_front(1);
	c[1]=1;
	while(!Q.empty()){
		ll p = Q.front();Q.pop_front();
		if(c[(p+1)%K]>c[p]+1){
			c[(p+1)%K]=c[p]+1;
			Q.push_back( (p+1)%K );
		}
		if(c[(p*10)%K]>c[p]){
			c[(p*10)%K]=c[p];
			Q.push_front( (p*10)%K );
		}
	}
	printf("%lld\n",c[0]);
}