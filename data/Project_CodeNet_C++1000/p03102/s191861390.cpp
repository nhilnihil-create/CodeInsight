#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<math.h>
#include<limits>
#include<list>
#include <stdio.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0;i < (n); ++i)
#pragma GCC optimize("Ofast")


int main(){
	int n, m, c;
	cin >> n >> m >> c;
	vector<int>b(m);
	rep(i, m)cin >> b[i];
	vector<vector<int>>a(n, vector<int>(m));
	rep(i, n) {
		rep(j, m)cin >> a[i][j];
	}
	int count = 0;
	vector<int>p(n,c);
	rep(i, n) {
		rep(j, m) {
			p[i] += (a[i][j] * b[j]);
			if (j == m - 1 && p[i] >0) {
				count++;
			}
		}
		
	}
	cout << count << endl;

	return 0;
}