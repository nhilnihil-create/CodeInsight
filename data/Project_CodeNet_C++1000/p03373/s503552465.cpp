#include <bits/stdc++.h>//復習必須
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
const int mod=1e9+7;
int main (){ 
   int a , b , c, x , y ;
   cin >> a >> b >> c >> x >> y;
 
	
	
	int mn = 1001001001;
 
	int m;
 
	for (int i = 0; i <= max(2*x,2*y); i = i + 2) {
 
		m = i * c + max(x - i/2, 0) * a + max(y - i/2, 0) * b;
		if (mn > m) {
			mn = m;
		}
 
	}
	cout << mn << endl;
 
}

 
