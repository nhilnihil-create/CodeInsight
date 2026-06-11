#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

int main(){
	int a, b;
	cin >> a >> b;

	int sum = 0;
	rep(i, 2){
		if(a < b){
			sum += b;
			b--;
		}else{
			sum += a;
			a--;
		}
	}

	cout << sum << endl;
	return 0;
}