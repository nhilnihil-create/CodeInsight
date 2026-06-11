#include<bits/stdc++.h>
using namespace std;

int maxtime(int x){
	return (x+9)/10*10;
}

int remtime(int x){
	return maxtime(x)-x;
}

int main(){
	int a,b,c,d,e;
	cin >> a >> b >> c >> d >> e;

	int ans = maxtime(a)+maxtime(b)+maxtime(c)+maxtime(d)+maxtime(e);
	ans -= max({remtime(a),remtime(b),remtime(c),remtime(d),remtime(e)});
	cout << ans << endl;
	return 0;
}