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
	int N;
	vector< pint > kukanl;
	vector< pint > kukanr;
	int L[100001],R[100001];
	int used[100001]={0};
	int leftside=0,rightside=0;
	scan(N);
	rep(i,N){
		scan(L[i]);scan(R[i]);
		kukanl.push_back(mp(L[i],i));
		kukanr.push_back(mp(R[i],i));
		if(L[i]>0) rightside++;
		if(R[i]<0) leftside++;
	}
	sort(kukanl.begin(),kukanl.end());
	sort(kukanr.rbegin(),kukanr.rend());
	ll kyori=0;
	int nowx=0;
	int usednum=0;
	int houkou;
	if(rightside>=leftside){
		houkou=1;
	}
	else{
		houkou=0;
	}
		rep(i,N){
			int selecti,selectl,selectr;
			if(houkou==1){
				selectl=kukanl.back().first;
				if(selectl<=nowx){
					kyori+=abs(nowx);
					break;
				}
				selecti=kukanl.back().second;
				if(used[selecti]==1){
					kukanl.pop_back();
					i--;
					continue;
				}
				kukanl.pop_back();
				used[selecti]=1;
				usednum++;
				kyori+=abs(nowx-selectl);
				nowx=selectl;
				houkou=0;
			}
			else{
				selectr=kukanr.back().first;
				if(selectr>=nowx){
					kyori+=abs(nowx);
					break;
				}
				selecti=kukanr.back().second;
				if(used[selecti]==1){
					kukanr.pop_back();
					i--;
					continue;
				}
				kukanr.pop_back();
				used[selecti]=1;
				usednum++;
				kyori+=abs(nowx-selectr);
				nowx=selectr;
				houkou=1;
			}
			if(i==N-1||kukanl.size()==0||kukanr.size()==0||usednum==N){
				kyori+=abs(nowx);
				break;
			}
		}
		prin(kyori);
	return 0;
}
