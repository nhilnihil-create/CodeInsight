#include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string>
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using namespace std;
#define P pair<int, int>
const int N = 300005;
int E[N];
int main () {
    int n;
    string s;
    cin >> n >> s;
    for (int i = n - 1; i >= 0; i--) {
		E[i] = E[i+1] + (s[i] == 'E');
	}
	int W = 0, res = n;
	for (int i = 0; i < n; i++) {
		res = min(res, W + E[i+1]);
		W += s[i] == 'W';
	}
	cout << res<< endl;
    return 0 ;

}

 
