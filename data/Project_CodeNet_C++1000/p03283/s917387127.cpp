//q079.cpp
//Sat Sep  5 11:25:55 2020

#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#define INTINF 2147483647
#define LLINF 9223372036854775807
#define MOD 1000000007
#define rep(i,n) for (int i=0;i<(n);++i)

using namespace std;
using ll=long long;
typedef pair<int,int> P;

int main(){
	int n,m,q;
	cin >> n >> m >> q;

	int rui[n+1][n+1];
	rep(i,n+1)rep(j,n+1) rui[i][j] = 0;
	rep(i,m){
		int l,r;
		cin >> l >> r;
		rui[l][r]++;
	}

	rep(i,n)rep(j,n) rui[i+1][j+1] += rui[i+1][j];
	rep(i,n)rep(j,n) rui[j+1][i+1] += rui[j][i+1];

	rep(i,q){
		int p,q;
		cin >> p >> q;
		cout << rui[q][q]-rui[q][p-1]-rui[p-1][q]+rui[p-1][p-1] << endl;
	}

//	printf("%.4f\n",ans);
}