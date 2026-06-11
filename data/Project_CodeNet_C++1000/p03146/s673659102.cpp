#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(void){
	int s;
	cin >> s;
	int a[1000005];
	a[1] = s;
	int i = 1;
	while(1){
		if (a[i]%2 == 0) a[i+1] = a[i]/2;
		else a[i+1] = 3*a[i] + 1;
		rep (j,i) {
			if (a[i+1] == a[j]){
				cout << i+1 << endl;
				return 0;
			}
		}
		i++;
	}

	return 0;
}
