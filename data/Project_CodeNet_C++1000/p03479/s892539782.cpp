#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);	
	long long int X, Y;
	cin >> X >> Y;
	int cnt = 0;
	while (X <= Y){
		++cnt;
		X *= 2;
	}
	cout << cnt << "\n";
	return 0;
}
