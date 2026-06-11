/*
Though leaves are many, the root is one;
Through all the lying days of my youth
I swayed my leaves and flowers in the sun,
Now may I wither into the truth.

- William Butler Yeats
*/
#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <cstdio>
#include <vector>
#include <set>
#include <cassert>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <sstream>
#include <functional>
#include <iomanip>
#include <bitset>
//#include <windows.h>  //Should be deleted when using AtCoder&POJ
using namespace std;

#define ll long long
#define pii pair<int,int>
#define qi ios::sync_with_stdio(0)
/**==Info==
*Program:1
*Problem:Distance Sums
*Date:2019-11-18
*Algorithm:Redo greedy and sorting
*Status:Unknown*/

bool debug=false;

#define pli pair<ll,int>

int n;
pli p[100005];
map<ll,ll> mp;

vector<pii> tree;

vector<int> nei[100005];

int dep[100005];
int sz[100005];

void dfs(int x,int fa){
	for(int i=0;i<nei[x].size();i++){
		if(nei[x][i]==fa){
			continue;
		}
		
		dep[nei[x][i]]=dep[x]+1;
		dfs(nei[x][i],x);
	}
}

void validate(){
	for(pii x:tree){
		nei[x.first].push_back(x.second);
		nei[x.second].push_back(x.first);
	}
	
	dfs(p[n-1].second,-1);
	
	ll dick=0;
	for(int i=0;i<n;i++){
		dick+=dep[i];
	}
	
	if(dick!=p[n-1].first){
		cout<<"-1";
		exit(0);
	}
}

int main(int argc,char* argv[]){
	cin>>n;
	for(int i=0;i<n;i++){
		ll x;
		cin>>x;
		mp[x]=i;
		p[i]=make_pair(x,i);
	}
	
	fill(sz,sz+n,1);
	
	sort(p,p+n);
	reverse(p,p+n);
	for(int i=0;i<n-1;i++){
		
		ll ans=p[i].first;
		int x=p[i].second;
		
		ll faShould=p[i].first+sz[x]-(n-sz[x]);
		if(!mp.count(faShould)){
			cout<<"-1";
			return 0;
		}
		
		ll par=mp[faShould];
		sz[par]+=sz[x];
		tree.push_back(make_pair(par,x));
	}
	
	validate();
	
	for(pii x:tree){
		cout<<x.first+1<<" "<<x.second+1<<endl;
	}
	return 0;
}

