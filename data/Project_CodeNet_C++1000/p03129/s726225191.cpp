#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<cstring>
#include<bitset>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<numeric>
#include<set>
#include<math.h>
#include<queue>
using namespace std;

const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };

#define rep(i,x) for(int i=0;i<x;i++)
#define re(i,x,y) for(int i=x;i<y;i++)

long long INF = 1e9;
const long long mod = 2019;
#define ll long long


int main() {
	cin.tie(0); ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	if (n % 2 == 0) {
		if (k > n / 2) {
			cout << "NO" << endl;
		}
		else {
			cout << "YES" << endl;
		}
	}
	else {
		if (k > n / 2 + 1) {
			cout << "NO" << endl;
		}
		else {
			cout << "YES" << endl;
		}
	}
	return 0;
}