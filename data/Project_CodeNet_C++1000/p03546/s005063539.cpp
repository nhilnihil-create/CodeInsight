#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <algorithm>

#include <bits/stdc++.h>
#include <cmath>
#include <limits>

using namespace std;
typedef long long LL;
using Graph = vector<vector<int>>;

static long long INF = (1LL<<62);

int H, W;
int c[12][12] = {0};
int m[10] = {1000+1}; //m[i]はiを1に変えるのに必要な最小魔力
int w[10] = {0};

int calcmp(vector<int> &v){
	int ret = 0;
	for(int i=v.size()-1; i>0; i--){
		ret += c[v[i]][v[i-1]];
	}
	return ret;
}

void dfs(int i, vector<int> &v1, vector<int> &v2){
	if(v2.size() >= 10 || i == 1){
		return;
	}
	
	v2.push_back(i);
	int v = calcmp(v2);
	if(m[i] > v){
		m[i] = v;
	}
	v2.pop_back();

	for(int j=0; j<v1.size(); j++){
		int a = v1[j];
		if(a == i || a < 0){
			continue;
		}
		v2.push_back(a);
		v1[j] = -1;
		dfs(i, v1, v2);
		v1[j] = a;
		v2.pop_back();
	}
}

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	for(int i=0; i<=9; i++){
		m[i] = 1000 + 1;
		w[i] = 0;
	}
	m[1] = 0;

	cin >> H >> W;
	for(int i=0; i<10; i++){
		for(int j=0; j<10; j++){
			cin >> c[i][j];
		}
	}

	for(int i=1; i<=H; i++){
		for(int j=1; j<=W; j++){
			int a;
			cin >> a;
			w[a]++;
		}
	}

	vector<int> v1, v2;
	v2.push_back(1);
	v1.push_back(0);
	for(int i=2; i<=9; i++) v1.push_back(i);

	for(int i=0; i<=9; i++){
		dfs(i, v1, v2);
	}

	long long ans = 0;
	for(int i=0; i<=9; i++){
		ans += (w[i] * m[i]);
	}

	printf("%lld\n", ans);
	return 0;
}