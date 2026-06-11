#include<bits/stdc++.h>
using namespace std;
 
int main(void){

	float a, t;
	int b;
	
	cin >> a >> b >> t;
	t += 0.5;
	
	int ans = 0;
	for(float i = a; i < t; i += a){
		ans += b;
	}
	
	cout << ans;

	return 0;
}