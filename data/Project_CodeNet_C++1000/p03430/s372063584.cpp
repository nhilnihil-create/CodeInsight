#include <bits/stdc++.h>
// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#include <time.h>
#define dibs reserve
#define OVER9000 1234567890
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-8
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
#define dbl long double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	string S;
	int K;
	cin >> S >> K;
	int N =S.length();
	vector< vector< vector<int> > > ans(N+1, vector< vector<int> >(N+1, vector<int>(K+1, -OVER9000)));
	ans[0][N][0] =0;
	for(int l =N; l > 0; l--) for(int i =0; i <= N-l; i++) {
		if(l == 1) {
			for(int k =0; k <= K; k++) ans[i][i][k] =max(ans[i][i][k], ans[i][i+1][k]+1);
			for(int k =0; k <= K; k++) ans[i][i+l-1][k] =max(ans[i][i+l-1][k], ans[i][i+l][k]);
			for(int k =0; k <= K; k++) ans[i+1][i+l][k] =max(ans[i+1][i+l][k], ans[i][i+l][k]);
			continue;
		}
		if(S[i] == S[i+l-1]) {
			for(int k =0; k <= K; k++) ans[i+1][i+l-1][k] =max(ans[i+1][i+l-1][k], ans[i][i+l][k]+2);
			continue;
		}
		for(int k =0; k <= K; k++) ans[i][i+l-1][k] =max(ans[i][i+l-1][k], ans[i][i+l][k]);
		for(int k =0; k <= K; k++) ans[i+1][i+l][k] =max(ans[i+1][i+l][k], ans[i][i+l][k]);
		for(int k =0; k < K; k++) ans[i+1][i+l-1][k+1] =max(ans[i+1][i+l-1][k+1], ans[i][i+l][k]+2);
	}
	int ansF =0;
	for(int i =0; i <= K; i++) for(int j =0; j <= N; j++) ansF =max(ansF, ans[j][j][i]);
	cout << ansF << "\n";
	return 0;}

// look at my code
// my code is amazing
