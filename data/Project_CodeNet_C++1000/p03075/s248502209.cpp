#include <bits/stdc++.h>

using namespace std;

int main(){

	int v[5],k;

	for(int i=0;i<5;++i) cin >> v[i];

	cin >> k;

	bool ok = true;

	for(int i=0;i<5;++i){
		for(int j=i+1;j<5;++j){
			if(v[j] - v[i] > k) ok = false;
		}
	}

	cout << (ok ? "Yay!" : ":(" ) << '\n';

	return 0;

}