#include<iostream>
#include<vector>
#include<cstdio>
#include<stdio.h>
#include<cstring>
#include<algorithm>

using namespace std;
typedef long long ll;

const int mod = 1e9+7; 

int main(){
	ios::sync_with_stdio(false);
	int m,n,ans= 0,curh,k,pos;
	cin >> n;
	vector<vector<int> > points(n, vector<int>(3));
	for(int i = 0; i < n; ++i){
		cin >> points[i][0];
		cin >> points[i][1];
		cin >> points[i][2];
		if(points[i][2] != 0)pos = i;
	}
	
	for(int i = 0; i <= 100; ++i){
		for(int j = 0; j <= 100; ++j){
			curh = abs(points[pos][0]-i) + abs(points[pos][1]-j) + points[pos][2];
			 
			for(k = 0; k < n; ++k){
				if(points[k][2] == 0){
					if(curh-points[k][2] > abs(points[k][0]-i) + abs(points[k][1]-j))break;
				}else if(curh-points[k][2] != abs(points[k][0]-i) + abs(points[k][1]-j))break;
			}
			if(k == n){
				cout << i << " " << j << " " << curh;
				return 0;
			}
		}
	}
	return 0;
} 