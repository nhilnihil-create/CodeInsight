/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	int a, b;
	cin >> a >> b;
	cout << max(a, b) + max(max(a, b) - 1, min(a, b));
}
