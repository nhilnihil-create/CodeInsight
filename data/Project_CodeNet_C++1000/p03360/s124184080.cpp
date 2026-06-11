#include <bits/stdc++.h>
using namespace std;

int main(){
	
	ios::sync_with_stdio(false);
	
	int k, v[3];
	cin >> v[0] >> v[1] >> v[2];
	cin >> k;
	
	sort(begin(v), end(v)); 	
	
	while (k--) v[2] = v[2]*2;

	cout << v[0] + v[1] + v[2] <<endl;
	
	return 0;
}