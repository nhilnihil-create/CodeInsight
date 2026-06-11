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
int main(){
	int N;
	ll x[200001];
	ll xsum[200001]={};
	ll X;
	scan(N);scan(X);
	ll iniE=N*X;
	rep(i,N){
		scan(x[i]);
		xsum[i+1]=xsum[i]+x[i];
	}
	ll ans=INFl;
	rep1(i,N){
		ll dropE=X*i;
		ll carryE=5*xsum[N];
		int overflow=0;
		for(int j=N-2*i;j>0;j-=i){
			carryE+=2*xsum[j];
			if(carryE<0){
				overflow=1;
				break;
			}
		}
		if(overflow) continue;
		ans=min(ans,carryE+dropE+iniE);
	}
	prin(ans);
	return 0;
}
