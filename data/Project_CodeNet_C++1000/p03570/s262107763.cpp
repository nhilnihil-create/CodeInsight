#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<map>
#include<tuple>
#define rep(index,num) for(int index=0;index<num;index++)
#define rep1(index,num) for(int index=1;index<=num;index++)
#define scan(argument) cin>>argument
#define prin(argument) cout<<argument<<endl
#define kaigyo cout<<endl
#define eps 1e-15
#define mp(a1,a2) make_pair(a1,a2)
#define ALPHANUM 26
typedef long long ll;
using namespace std;
typedef pair<ll,ll> pll;
typedef pair<int,int> pint;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<pint> vpint;
typedef vector<pll> vpll;
ll INFl=1e+18+1;
int INF=1e+9+1;
ll guukiruiseki[200001]={};
int opt[200001];
int dp[(1<<ALPHANUM)];
bool kaibun(int left,int right){
	ll info=guukiruiseki[left]^guukiruiseki[right];
	if(info-(info & -info)==0) return true;
	else return false;
}
int main(){
	fill_n(dp,1<<ALPHANUM,INF);
	string S;
	scan(S);
	int maxN=S.size();
	rep1(i,maxN){
		guukiruiseki[i]=guukiruiseki[i-1]^(1<<(S[i-1]-'a'));
	}
	opt[0]=0;
	dp[0]=0;
	rep1(i,maxN){
		int mindp=INF;
		rep(j,ALPHANUM+1){
			int x;
			if(j==0) x=0;
			else x=(1<<(j-1));
			mindp=min(mindp,dp[guukiruiseki[i]^x]);
		}
		opt[i]=mindp+1;
		dp[guukiruiseki[i]]=min(dp[guukiruiseki[i]],opt[i]);
	}
	prin(opt[maxN]);
	return 0;
}
