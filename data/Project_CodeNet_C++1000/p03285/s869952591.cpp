#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, total;
	bool finish=false;
	cin >> n;
	for (int i=0; 4*i<=n; i++) {
		for (int j=0; 7*j<=n; j++) {
			total=4*i+7*j;
			if(total==n) {
				finish = true;
				break;
			}
		}
		if(finish) break;
	}
	if(finish) cout << "Yes" << endl;
	else cout <<"No" << endl;
}
