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
#define MAX_N 500
int field[MAX_N+1][MAX_N+1];
int cumSum[MAX_N+1][MAX_N+1];

void init(){
	rep(i,MAX_N+1){
		rep(j,MAX_N+1){
			field[i][j] = 0;
			cumSum[i][j] = 0;
		}
	}
}

int main()
{
	init();
	int N,M,Q;
	cin>>N>>M>>Q;
	rep(i,M){
		int l,r;
		cin>>l>>r;
		field[l][r]++;
	}
	for(int i = 0; i < N+1; i++){
		for(int j = 0; j < N+1; j++){
			cumSum[i+1][j+1] = cumSum[i+1][j] + cumSum[i][j+1] -cumSum[i][j] + field[i+1][j+1];
		}
	}

	rep(i,Q){
		int p,q;
		cin>>p>>q;
		cout<<cumSum[q][q] - cumSum[p-1][q] - cumSum[q][p-1] + cumSum[p-1][p-1]<<endl;
	}
	/*rep(i,N+1){
		rep(j,N+1){
			cout<<field[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"--------------------------"<<endl;
	rep(i,N+1){
		rep(j,N+1){
			cout<<cumSum[i][j]<<" ";
		}
		cout<<endl;
	}*/
	return 0;
}
