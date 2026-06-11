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
	int N,K,Q;
	ll A[2001];
	vpll Asort;
	bool pickok[2001];
	ll minsa=INFl;
	scan(N);scan(K);scan(Q);
	rep(i,N){
		scan(A[i]);
		Asort.push_back(mp(A[i],i));
		pickok[i]=true;
	}
	pickok[N]=false;
	sort(Asort.begin(),Asort.end());
	ll nextfalse;
	rep(i,N){
		ll X=Asort[i].first;
		if(i!=0) pickok[nextfalse]=false;
		nextfalse=Asort[i].second;
		//printf("i:%d X:%lld nextfalse:%lld\n",i,X,nextfalse);
		vll stock;
		vll stockall;
		int retusize=0;
		rep(j,N+1){
			//printf("i:%d j:%d\n",i,j);
			if(pickok[j]){
				stock.push_back(A[j]);
				retusize++;
			}
			else{
				//printf("i:%d j:%d retusize:%d\n",i,j,retusize);
				if(retusize>=K){
					sort(stock.begin(),stock.end());
					rep(k,stock.size()-K+1){
						stockall.push_back(stock[k]);
					}
				}
				retusize=0;
				stock.clear();
			}
		}
		if(stockall.size()<Q) continue;
		sort(stockall.begin(),stockall.end());
		ll Y=stockall[Q-1];
		minsa=min(minsa,Y-X);
		//printf("i:%d stockallsize:%d Y:%lld minsa:%lld\n",i,stockall.size(),Y,minsa);
	}
	prin(minsa);
	return 0;
}
