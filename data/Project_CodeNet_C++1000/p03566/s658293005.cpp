//https://atcoder.jp/contests/abc076/tasks/abc076_d
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
#include<iomanip>
#include<set>
#define rep(index,num) for(int index=0;index<num;index++)
#define rep1(index,num) for(int index=1;index<=num;index++)
#define scan(argument) cin>>argument
#define prin(argument) cout<<argument<<endl
#define kaigyo cout<<endl
#define eps 1e-7
#define mp(a1,a2) make_pair(a1,a2)
typedef long long ll;
typedef long double ld;
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
	int t[201],v[201];
	int ruit[201]={};
	double speed[44000];
	int kukan[44000];
	double ans=0;
	scan(N);
	int now=0;
	rep(i,N){
		scan(t[i]);
		for(int jikan=now;jikan<now+t[i]*2;jikan++){
			kukan[jikan]=i;
		}
		ruit[i+1]=ruit[i]+t[i]*2;
		now+=t[i]*2;
	}
	rep(i,N){
		scan(v[i]);
	}
	rep(i,now){
		speed[i]=min(0.5*i,-0.5*i+now/2);
		rep(j,N){
			if(kukan[i]<j){
				speed[i]=min(speed[i],-0.5*i+ruit[j]/2+v[j]);
			}
			else if(kukan[i]>j){
				speed[i]=min(speed[i],0.5*i-ruit[j+1]/2+v[j]);
			}
			if(kukan[i]==j||(i>0&&kukan[i-1]==j)){
				speed[i]=min(speed[i],(double)v[j]);
			}
		}
	}
	speed[now]=0;
	rep(i,now){
		//printf("now:%d i:%d kukan:%d v[kukan]:%d speed:%f\n",now,i,kukan[i],v[kukan[i]],speed[i]);
		ans+=(speed[i]+speed[i+1])*0.25;
	}
	prin(setprecision(10)<<ans);
	return 0;
}
