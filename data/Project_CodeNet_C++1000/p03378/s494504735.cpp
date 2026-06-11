#include<bits/stdc++.h>
using namespace std;

int n, m, x;

int main(void){
	cin >> n >> m >> x;
	vector<int> v(n+1);
	for(int i = 0; i < m; i++){
		int a;
		cin >> a;
		v[a] = 1;
	}
	int r1 = 0;
	for(int i = x+1; i < n+1; i++) r1+=v[i];
	int r2 = 0;
	for(int i = x-1; i >= 0; i--) r2+=v[i];
	cout << min(r1, r2) << endl;
	return 0;
}
