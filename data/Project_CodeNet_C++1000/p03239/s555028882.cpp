#include <bits/stdc++.h>
using namespace std;
int main (){
	int n,t,x,y;
	cin >> n>>t;
	int min = 1001;
	for (int i=0;i<n;i++){
		cin >> x >> y;
		if (y <= t){
			if (x < min) min = x;
		}		
	}
	if (min == 1001) cout << "TLE";
	else cout << min;
	
	return 0;
}