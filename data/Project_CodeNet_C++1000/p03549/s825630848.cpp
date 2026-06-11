#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

lli n, m;

int main(void){
	cin >> n >> m;
	lli c = 1;
	rep(i, m) c*=2;
	cout << c*(1900*m+100*(n-m)) << endl;
	return 0;
}
