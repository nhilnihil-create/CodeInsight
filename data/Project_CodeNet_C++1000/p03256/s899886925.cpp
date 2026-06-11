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
vint connect[200001];
int irovertex[200001][2]={0};
int iro[200001];
bool kindsmallerthan1flag[200001];
int main(){
	int N,M;
	string s;
	vpint edge;
	vint kindsmallerthan1;
	scan(N);scan(M);
	scan(s);
	rep1(i,N){
		if(s[i-1]=='A') iro[i]=0;
		else iro[i]=1;
	}
	rep(i,M){
		int a,b;
		scan(a);scan(b);
		connect[a].push_back(b);
		connect[b].push_back(a);
		irovertex[a][iro[b]]++;
		irovertex[b][iro[a]]++;
	}
	rep1(i,N){
		if(irovertex[i][0]==0||irovertex[i][1]==0){
			kindsmallerthan1flag[i]=true;
			kindsmallerthan1.push_back(i);
		}
		else{
			kindsmallerthan1flag[i]=false;
		}
	}
	while(kindsmallerthan1.size()!=0){
		int moto=kindsmallerthan1.back();
		kindsmallerthan1.pop_back();
		rep(i,connect[moto].size()){
			int saki=connect[moto][i];
			if(kindsmallerthan1flag[saki]==0){
				irovertex[saki][iro[moto]]--;
				if(irovertex[saki][iro[moto]]==0){
					kindsmallerthan1flag[saki]=true;
					kindsmallerthan1.push_back(saki);
				}
			}
		}
	}
	bool flag=1;
	rep1(i,N){
		flag=(flag&&kindsmallerthan1flag[i]);
	}
	if(!flag) prin("Yes");
	else prin("No");
	return 0;
}
