#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, m, x;
	cin >> n >> m >> x;
	int t, less=0, more=0;
	for (int i=0; i<m; i++){
		cin >> t;
		if (t<x) less++;
		else more++;
	}
	cout << min(less, more) << "\n";
}