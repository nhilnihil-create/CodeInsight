#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

int n;

int main(void){
	cin >> n;
	vector<lli> r(n+1);
	r[0] = 2;
	r[1] = 1;
	for(int i = 2; i <= n; i++) r[i] = r[i-1]+r[i-2];
	cout << r[n] << endl;
	return 0;
}
