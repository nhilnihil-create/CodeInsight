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
#define abs(x) (((x) < 0)?-(x):(x))
#define uint unsigned int
#define dbl long double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

using cat = long long;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	vector<cat> X[2];
	X[0].resize(N);
	X[1].resize(N);
	for(int i = 0; i < N; i++) cin >> X[0][i] >> X[1][i];
	for(int i = 1; i < N; i++) if((X[0][i]+X[1][i]-X[0][0]-X[1][0])%2 != 0) {
		cout << "-1\n";
		return 0;
	}
	vector<cat> lengths;
	for(int i = 0; i < 33; i++) lengths.push_back(1LL<<i);
	if((X[0][0]+X[1][0])%2 == 0) lengths.push_back(1);
	int L = lengths.size();
	cout << L << "\n";
	for(int i = 0; i < L; i++) cout << lengths[i] << ((i == L-1) ? "\n" : " ");
	for(int i = 0; i < N; i++) {
		string s;
		for(int j = 0; j < L; j++) s += '?';
		string dir = "UDLR";
		int d[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
		for(int j = L-1; j >= 0; j--) {
			cat maxdist = 0;
			for(int k = 0; k < j; k++) maxdist += lengths[k];
			cat l = lengths[j];
			for(int k = 0; k < 4; k++) {
				if(abs(X[0][i]-d[k][0]*l)+abs(X[1][i]-d[k][1]*l) > maxdist) continue;
				X[0][i] -= d[k][0]*l;
				X[1][i] -= d[k][1]*l;
				s[j] = dir[k];
				break;
			}
		}
		cout << s << "\n";
	}
	return 0;
}

// look at my code
// my code is amazing
