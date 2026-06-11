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
#include<bitset>
#include<iomanip>
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
vpint mode;
int twoflag=0;
void nextmode(int K,int pushed,bool buchikowa){
	if(mode.back().first<pushed){
		if(buchikowa==0) mode.push_back({pushed,1});
		else{
			mode.push_back({pushed,2});
			twoflag=2;
		}
		return;
	}
	else if(mode.back().first==pushed){
		mode.back().second++;
		if(mode.back().first>1&&mode.back().second>K){
			mode.pop_back();
			nextmode(K,pushed-1,0);
			mode.push_back({pushed,1});
		}
	}
	else{
		mode.pop_back();
		nextmode(K,pushed,1);
	}
}
int main(){
	int N;
	int A[200001];
	int Kmin=0,Kmax=INF;
	scan(N);
	rep(i,N){
		scan(A[i]);
	}
	while(Kmin+1<Kmax){
		int Kmid=(Kmin+Kmax)/2;
		mode.clear();
		mode.push_back({1,1});
		rep(i,N){
			if(i==0&&A[i]==1) continue;
			nextmode(Kmid,A[i],0);
			/*rep(j,mode.size()){
				printf("(%d,%d) ",mode[j].first,mode[j].second);
			}
			kaigyo;*/
		}
		if(mode.size()>=1&&mode[0].first==1&&max(mode[0].second,twoflag)>Kmid){
			//printf("Kmid:%d failed\n",Kmid);
			Kmin=Kmid;
		}
		else{
			Kmax=Kmid;
			//printf("Kmid:%d successed\n",Kmid);
		}
	}
	prin(Kmax);
	return 0;
}
