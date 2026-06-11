#include <stdio.h>
#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cmath>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;

#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define ldb ldouble

typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

int IT_MAX = 1 << 19;
int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

const int MX = 8005*2;

bool check(vector<int> &X, int val){
//	for(int c : X) printf("%d ", c); printf("\n%d\n", val);
	int arr[2][MX] = {};
	int *S = arr[0], *E = arr[1];
	S[MX/2] = 1;
	for(int c : X){
		for(int i = 0; i < MX; i++) E[i] = 0;
		for(int i = 0; i < MX; i++){
			if( i >= c ) E[i] |= S[i-c];
			if( i+c < MX ) E[i] |= S[i+c];
		}
		swap(S, E);
	}
	return S[MX/2 + val];
}

int main()
{
	string D;
	int X, Y;
	cin >> D >> X >> Y;
	vector<int> H, V;
	for(int i = 0; i <= D.size(); i++){
		if( i < D.size() && D[i] == 'F' ) X--;
		else{
			D = D.substr(i, -1);
			break;
		}
	}
	int cnt = 0, flag = 1;
	for(int i = 0; i <= D.size(); i++){
		if( i < D.size() && D[i] == 'F' ) cnt++;
		else{
			if( !cnt );
			else if( flag ) H.push_back(cnt);
			else V.push_back(cnt);
			flag ^= 1; cnt = 0;
		}
	}
	if( check(V, Y) && check(H, X)) printf("Yes\n");
	else printf("No\n");
}
