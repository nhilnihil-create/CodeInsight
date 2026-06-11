#include <iostream>
#include <algorithm>
#include <string> 
#include <math.h>
#include <set>
#include <vector>
#define rep(i,n) for(int i=0; i< (int)(n); ++i)
using namespace std;


int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int a,b,c,x,y;
	cin >> a >> b >> c >> x >> y;
	int ans;
	if(2*c > (a+b)) ans = a*x + b*y;
	else{
		if(x > y) ans = 2*c*y + min(2*c,a)*(x-y);
		else ans = 2*c*x + min(2*c,b)*(y-x);
	}
	cout << ans << "\n";
} 
