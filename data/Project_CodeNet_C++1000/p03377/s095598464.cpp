#include <bits/stdc++.h>
using namespace std;

int main(){
	
	ios::sync_with_stdio(false);
	
	int a, b, x;
	cin >> a >> b >> x;
	
	if (x >= a && x <= a+b) puts ("YES");
	else puts ("NO");

	return 0;
}