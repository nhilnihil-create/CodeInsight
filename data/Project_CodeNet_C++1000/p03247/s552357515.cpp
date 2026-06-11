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
int sign(int n){
	return (n>0)-(n<0);
}
int main(){
	int N;
	int flag=1;
	int X[1001],Y[1001];
	int distmod;
	int distmax=0;
	char MC[4]={'D','L','U','R'};
	string w[1001];
	vll d;
	scan(N);
	rep(i,N){
		scan(X[i]);scan(Y[i]);
		if(i==0) distmod=(abs(X[i])+abs(Y[i]))%2;
		else{
			if(distmod!=(abs(X[i])+abs(Y[i]))%2) flag=0;
		}
		distmax=max(distmax,abs(X[i])+abs(Y[i]));
	}
	if(flag==0) prin("-1");
	/*else if(flag&&distmax<=40){
		int m=distmax;
		if(m==0) m=2;
		prin(m);
		rep(i,m) printf("%d ",1);
		kaigyo;
		rep(i,N){
			int dist=abs(X[i])+abs(Y[i]);
			rep(xa,abs(X[i])){
				if(X[i]>0) printf("R");
				else printf("L");
			}
			rep(ya,abs(Y[i])){
				if(Y[i]>0) printf("U");
				else printf("D");
			}
			rep(k,(m-dist)/2){
				printf("LR");
			}
			kaigyo;
		}
	}*/
	else{
		int m;
		if(distmod==0) m=33;
		else m=32;
		prin(m);
		for(int i=31;i>=0;i--){
			printf("%lld ",1LL<<i);
		}
		if(distmod==0) printf("1");
		kaigyo;
		rep(i,N){
			ll x=X[i],y=Y[i];
			for(int j=31;j>=0;j--){
				if(x+y>0&&x-y>0){
					printf("R");
					x-=(1LL<<j);
				}
				else if(x+y>0&&x-y<=0){
					printf("U");
					y-=(1LL<<j);
				}
				else if(x+y<=0&&x-y>0){
					printf("D");
					y+=(1LL<<j);
				}
				else if(x+y<=0&&x-y<=0){
					printf("L");
					x+=(1LL<<j);
				}
			}
			if(distmod==0){
				printf("%c",MC[(x+1)*(y+2)-1]);
			}
			kaigyo;
		}
	}
	return 0;
}
