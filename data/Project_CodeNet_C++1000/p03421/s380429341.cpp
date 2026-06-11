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
int lis(int N,vint a){
	vint L;
	rep(i,N){
		if(i!=0){
			if(L.back()<a[i]){
				L.push_back(a[i]);
			}
			else{
				L.at(lower_bound(L.begin(),L.end(),a[i])-L.begin())=a[i];
			}
		}
		else{
			L.push_back(a[i]);
		}
	}
	return L.size();
}
int lds(int N,vint a){
	rep(i,N){
		a[i]=-a[i];
	}
	vint L;
	rep(i,N){
		if(i!=0){
			if(L.back()<a[i]){
				L.push_back(a[i]);
			}
			else{
				L.at(lower_bound(L.begin(),L.end(),a[i])-L.begin())=a[i];
			}
		}
		else{
			L.push_back(a[i]);
		}
	}
	return L.size();
}
int main(){
	int N;
	vint retu;
	int A,B;
	scan(N);scan(A);scan(B);
	if(N/A+(N%A!=0)<=B&&B<=N-A+1){
		if(min(A,B)==1){
			if(A+B==N) retu.push_back(-1);
			else{
				if(A==1){
					rep(i,N) retu.push_back(N-i);
				}
				else{
					rep1(i,N) retu.push_back(i);
				}
			}
		}
		else{
			for(int i=N-A+1;i<=N;i++){
				retu.push_back(i);
			}
			int husayouso=(N-A)/(B-1);
			int amarihusa=(N-A)%(B-1);
			int initialnum=N-A+1;
			for(int husa=1;husa<=B-1;husa++){
				int husanum;
				if(husa<=amarihusa) husanum=husayouso+1;
				else husanum=husayouso;
				initialnum-=husanum;
				for(int tama=initialnum;tama<initialnum+husanum;tama++){
					retu.push_back(tama);
				}
			}
		}
	}
	else{
		retu.push_back(-1);
	}
	rep(i,retu.size()){
		printf("%d ",retu[i]);
	}
	kaigyo;
	//if(retu.size()==N) printf("lis:%d lds:%d\n",lis(N,retu),lds(N,retu));
	return 0;
}
