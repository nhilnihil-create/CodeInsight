#pragma GCC optimize("Ofast")
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<map>
#include<iomanip>
#include<queue>

const long long INF = 1e17+7;
const long long MOD = 1e9+7;
const double PI=acos(-1);

using namespace std;

int main(){
	int n,t;
	cin >> n >> t;
	int cost=999999;
	vector<pair<int,int>> pa(n);
	for(int i=0;i<n;i++){
		cin >> pa[i].first;
		cin >> pa[i].second;
		if(pa[i].second<=t){
			cost=min(cost,pa[i].first);
		}
	}
	if(cost==999999){
		cout << "TLE" << endl;
	}else{
		cout << cost << endl;
	}
	return 0;
}
