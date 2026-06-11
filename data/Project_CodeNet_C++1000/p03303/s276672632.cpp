#include <bits/stdc++.h>
using namespace std;


int main() {
	string S;
	int n;
	cin >> S >> n;
	string ans;
	for(int i = 0; i < S.size(); i++){
		if(i % (n) == 0){
			ans += S[i ];
		}
	}
	cout << ans << endl;
}

