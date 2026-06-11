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
	ll A[200001],B[200001];
	ll Asum=0,Bmin=INFl;
	int sameflag=1;
	scan(N);
	rep(i,N){
		scan(A[i]);scan(B[i]);
		if(A[i]!=B[i]) sameflag=0;
		Asum+=A[i];
		if(A[i]>B[i]) Bmin=min(Bmin,B[i]);
	}
	if(sameflag) prin(0);
	else prin(Asum-Bmin);
	return 0;
}
