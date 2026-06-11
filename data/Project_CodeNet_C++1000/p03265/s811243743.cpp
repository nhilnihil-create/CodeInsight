#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
	ios::sync_with_stdio(false);
	int x1,y1,x2,y2; cin>>x1>>y1>>x2>>y2;

	int x3,y3,x4,y4;
	x3 = -(y2-y1) + x2;
	y3 = (x2-x1) + y2;
	x4 = -(y2-y1) + x1;
	y4 = (x2-x1) + y1;

	cout << x3 << " " << y3 << " " << x4 << " " << y4 <<endl;
}
