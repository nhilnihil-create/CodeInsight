#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m, temp;
	cin >> n >> m;
	vector<int> v(m,0);
	for(int i = 0;i<n;i++){
		int k;
		cin >> k;
		for(int j =0; j<k; j++){
			cin >> temp;
			v[temp-1]++;
		}
	}
	int count = 0;
	for(int i = 0; i<m; i++){
		if (v[i] == n) count++;
	}
	cout << count;
}
