#include <bits/stdc++.h>
using namespace std;
int main(){
	long long ans = 0;
	string s;
	cin >> s;

	int n = s.length();
	int numB = 0;
	for(int i = 0; i < n; i++){
		string stone = s.substr(i, 1);
		if(stone == "B") numB++;
		else ans += numB;
	}
	
	cout << ans << endl;
}