#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

int main(){
	int a = 1000;
	int e = 0;
	int k;
	rep(i, 6){
		int d;
		cin >> d;
		if(i == 5){
			k = d;
			break;
		}
		a = min(a, d);
		e = max(e, d);
	}

	if(e-a <= k) cout << "Yay!" << endl;
	else cout << ":(" << endl;

	return 0;
}