#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int N, Y;
	cin >> N >> Y;
	Y /= 1000;
	rep(i,Y/10+2)rep(j,Y/5+2){
		int k = N-i-j;
		if (k < 0 ) break;
		if (10*i+5*j+k == Y) {
			cout << i << " " << j << " " << k << endl;
			return 0;
		}
	}
	cout << "-1 -1 -1" << endl;

	return 0;
}
