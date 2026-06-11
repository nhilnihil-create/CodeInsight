#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);	
	int A, B; cin >> A >> B;
	string s; cin >> s;
	bool ans = true;
	for (int i = 0; i < s.length(); ++i){
		if (i == A && s[i] != '-'){
				ans = false;	
		}else if (i != A){
			if (!(s[i] - '0' >= 0 && s[i] - '0' <= 9)){
				ans = false;
			}
		}
	}	
	cout << (ans ? "Yes" : "No") << "\n";
	return 0;
}
