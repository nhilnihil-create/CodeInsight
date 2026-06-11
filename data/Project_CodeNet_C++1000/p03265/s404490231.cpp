#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

int x[4];
int y[4];

int main(void){
	cin >> x[0] >> y[0] >> x[1] >> y[1];
	int s, t;
	s = x[1]-x[0];
	t = y[1]-y[0];
	x[2] = x[1]-t;
	y[2] = y[1]+s;
	x[3] = x[2]-s;
	y[3] = y[2]-t;
	cout << x[2] << " " <<  y[2] << " " << x[3] << " " << y[3] << " " <<  endl;
	return 0;
}
