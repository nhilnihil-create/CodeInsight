#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<climits>
#include<string>
#include<set>
#include<numeric>
#include<map>
#include<iostream>
#include<iomanip>
using namespace std;
#define rep(i,n) for(int i = 0;i<((int)(n));i++)
#define reg(i,a,b) for(int i = ((int)(a));i<=((int)(b));i++)
#define irep(i,n) for(int i = ((int)(n)-1);i>=0;i--)
#define ireg(i,a,b) for(int i = ((int)(b));i>=((int)(a));i--)
typedef long long ll;
typedef pair<ll, ll> mp;


/*
s+wが小さい順に載せるのが最適
*/

struct D{
	ll w,s,v,id;
};
bool operator<(const D &lhs, const D &rhs){
	if(lhs.w+lhs.s<rhs.w+rhs.s){
		return true;
	}else if(lhs.w+lhs.s==rhs.w+rhs.s){
		return lhs.id<rhs.id;
	}
	return false;
}

ll n,dp[20010]={},ans=0;
D block[1010];

int main(void){
	cin>>n;
	rep(i,n){
		ll w,s,v;
		cin>>w>>s>>v;
		block[i]={w,s,v,i};
	}
	//
	sort(block,block+n);
	//
	rep(i,n){
		ireg(j,0,block[i].s){
			if(j+block[i].w>20000)break;
			dp[j+block[i].w]=max(dp[j+block[i].w],dp[j]+block[i].v);
		}
	}
	rep(i,20010)ans=max(ans,dp[i]);
	cout<<ans<<endl;
	return 0;
}