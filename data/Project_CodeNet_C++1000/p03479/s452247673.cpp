#include<bits/stdc++.h>

using namespace std;

long long ans, x, y;

int main(){
	cin >> x >> y;
	while(x <= y){
		ans++;
		x*=2;
	}
	cout << ans << endl;
}