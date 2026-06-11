#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int a,b,c,x,y;
	cin >> a >> b >> c >> x >> y;
	c *= 2;
	ll sum = 0;
	int z = min(x,y);
	if(a+b > c){
		if(x > y){
			int cost1 = c*x;
			int cost2 = (x-y)*a + y*c;
			sum = min(cost1,cost2);
		}
		else{
			int cost1 = c*y;
			int cost2 = (y-x)*b + x*c;
			sum = min(cost1,cost2);
		}
	}
	else{
		sum = a*x + b*y;
	}
	cout << sum << endl;
}