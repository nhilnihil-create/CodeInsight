/*
* AUTHOR : Haoyang(Max) Chen
* INSTITUTION : Australian National Unversity
*/

#include <iostream>
#include <cstdlib>
using namespace std;

#define ll long long

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll ans;
	int X, Y;
	int temp = 2;

	cin >> X >> Y;

	if (X % Y == 0) {
		cout << -1 << endl;
	}
	else {
		bool isMultipleY = false;
		while(!isMultipleY){
			ans = temp * X;
			if (ans % Y != 0){
				isMultipleY = true;
			}else{
				temp += 1;
			}
		}
		cout << ans << endl;
	}

	return 0;
}
