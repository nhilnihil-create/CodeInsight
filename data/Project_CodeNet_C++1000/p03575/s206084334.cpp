#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

using namespace std;
typedef long long int ll;
#define MAX_N 10000

int par[MAX_N];
struct edge{
	int start;
	int to;
};

void init(){
	rep(i,MAX_N){
		par[i] = i;
	}
}

int root(int i){
	if(par[i] == i) return i;
	par[i] = root(par[i]);
	return par[i];
}

bool isSame(int i,int j){
	i = root(par[i]);
	j = root(par[j]);
	return i == j;
}

void unite(int i, int j){
	i = root(i);
	j = root(j);
	if(i == j) return;
	par[i] = j;
}


int main()
{
	int N,M;
	cin>>N>>M;
	vector<edge> edgeList;
	rep(i,M){
		int x,y;
		cin>>x>>y;
		x--;
		y--;
		struct edge e;
		e.start = x;
		e.to = y;
		edgeList.push_back(e);
	}
	ll ans = 0;
	for(int i = 0; i < M; i++){
		init();
		for(int j = 0; j < M; j++){
			if( i != j){
				unite(edgeList[j].start, edgeList[j].to);
			}
		}
		/*rep(k,N) cout<<par[k]<<" ";
		cout<<endl;*/
		if( isSame(edgeList[i].start,edgeList[i].to) == false) ans++;
	}
	cout<<ans<<endl;
	return 0;
}
