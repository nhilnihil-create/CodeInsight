#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)

typedef long long ll;

int main(){
	rep(i,3)rep(j,3){
		char c; cin >> c;
		if(i==j)cout << c;
	}
	cout << endl;
	return 0;
}