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


void dfs(vector<int> v, long long &c){
	if(v.size() == 0) return;
	if(v.size() == 1){
		c += v[0];
		return;
	}

	int ezero = 0;
	for(int i=0; i<v.size(); i++){
		if(v[i] == 0){
			ezero = 1;
			break;
		}
	}

	vector<int> w;
	if(ezero == 0){
		c++;
		for(int i=0; i<v.size(); i++){
			w.push_back(v[i] - 1);
		}
		dfs(w, c);
		return;
	}
	for(int i=0; i<v.size(); i++){
		if(v[i] != 0){
			w.push_back(v[i]);
			if(i == v.size() - 1){
				dfs(w, c);
				w.clear();
			}
		}
		else if(v[i] == 0){
			dfs(w, c);
			w.clear();
		}
	}
}

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N;
	vector<int> H;

	cin >> N;
	for(int i=0; i<N; i++){
		int  h;
		cin >> h;
		H.push_back(h);
	}
	long long ans = 0;
	dfs(H, ans);
	cout << ans << endl;
	return 0;
}