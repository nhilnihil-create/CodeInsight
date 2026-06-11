#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<stack>
#include<queue>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
//#include<bits/stdc++.h>
using namespace std;
const int R = 1e4 + 10;
int n;
long long a[R], b[R];
unsigned long long as, bs;
int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++) {
		cin >> b[i];
	}
	for(int i = 1; i <= n; i++) {
		if(a[i] > b[i]) as += a[i] - b[i];
		else bs += (b[i] - a[i]) / 2;
	}
	if(as <= bs) cout << "Yes";
	else cout << "No";
}
