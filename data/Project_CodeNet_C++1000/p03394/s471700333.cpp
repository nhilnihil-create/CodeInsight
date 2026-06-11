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
#define YMAX 250001
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
	int MAX=30000;
	int N;
	vint ni,san,roku;
	scan(N);
	rep1(i,MAX){
		if(i%6==0){
			roku.push_back(i);
		}
		else if(i%2==0){
			ni.push_back(i);
		}
		else if(i%3==0){
			san.push_back(i);
		}
	}
	int nikosu,sankosu,rokukosu;
	if(N==3) printf("2 5 63\n");
	else{
		if(N>=15000){
			nikosu=10000;
			sankosu=5000;
			rokukosu=N-15000;
		}
		else if(N>=10002){
			nikosu=10000;
			sankosu=N-10000;
			rokukosu=0;
			if(sankosu%2==1){
				sankosu--;
				rokukosu++;
			}
		}
		else{
			nikosu=N-2;
			sankosu=2;
			rokukosu=0;
			if(nikosu%2==1){
				nikosu--;
				rokukosu++;
			}
		}
		rep(i,nikosu){
			printf("%d ",ni[i]);
		}
		rep(i,sankosu){
			printf("%d ",san[i]);
		}
		rep(i,rokukosu){
			printf("%d ",roku[i]);
		}
		kaigyo;
	}
	return 0;
}
