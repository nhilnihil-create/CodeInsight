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
#define MAX_N 100001

int par[MAX_N];
int siz[MAX_N];

struct edge{
	int start;
	int to;
};

void init(){
	rep(i,MAX_N){
		par[i] = i;
		siz[i] = 1;
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
	if(siz[i] > siz[j]){
		int temp = i;
		i = j;
		j = temp;
	}
	par[i] = j;
	siz[j] += siz[i];
}

ll howLong(int i){
	return siz[root(i)];
}

int main()
{
	ll N,M;
	cin>>N>>M;
	vector<edge> edgeList;
	vector<ll> ans(M+1);
	rep(i,M){
		ll x,y;
		cin>>x>>y;
		x--;
		y--;
		struct edge e;
		e.start = x;
		e.to = y;
		edgeList.push_back(e);
	}
	init();
	ans[M] = N*(N-1)/2;
	for(ll i = M-1; i >= 0; i--){
		if( isSame(edgeList[i].start,edgeList[i].to) == true){
			ans[i] = ans[i+1];
			unite(edgeList[i].start,edgeList[i].to);
		}else{
			ans[i] = ans[i+1] - howLong(edgeList[i].start)*howLong(edgeList[i].to);
			unite(edgeList[i].start,edgeList[i].to);
		}
	}
	rep(i,M){
		cout<<ans[i+1]<<endl;
	}
	return 0;
}
