#include <bits/stdc++.h>
using namespace std;
long long q, x, y;
long long count(int x, int y){
	if(x==y)
		return 2*x-2;
	long long s = (long long)x*y;
	long long c = sqrt(s);
	if(c*c == s){
		return y-1+c-1+c-1-y;
	}
	else if(c*(c+1)<s){
		return y-1+c-y+c;
	}
	return	y-1+c-y+c-1;
	
}
int main() {
	cin>>q;
	while(q--){
		cin>>x>>y;
		if(y>x)	swap(x,y);
		cout<<count(x,y)<<'\n';
	}
	return 0;
}