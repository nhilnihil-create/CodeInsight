#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long LL;

int n,k;

int main(){
	cin >> n >> k; n = (1 << n);
	if(k >= n){ cout << -1 << endl; return 0; }
	if(n == 1){ cout << 0 << ' ' << 0 << endl; return 0; }
	if(n == 2){
		if(k == 0) cout << 0 << ' ' << 0 << ' ' << 1 << ' ' << 1 << endl;
		else cout << -1 << endl; return 0;
	}
	for(int i = 0;i < n;i ++) if(i != k) cout << i << ' ';
	cout << k << ' ';
	for(int i = n - 1;i >= 0;i --) if(i != k) cout << i << ' ';
	cout << k << endl;
	return 0;
}