#include <iostream>
#include <vector>
using namespace std;

int main(void){
	string s; cin >> s; bool ok = true; int n = s.size();
	if (s[0]=='0' || s[n-2]=='0' || s[n-1]=='1') ok = false;
	for(int i=2; i <= n-i; i++){
		if (s[i-1] != s[n-i-1]) ok = false;
		//cout << i << " " << n-i << endl;
	}
	if (!ok) {cout << -1 << endl; return 0;}
	s[n-1]='1';
	int w[n];
	for(int i=n-1; i>=0; i--) {
		if (s[i] == '1') w[i] = i+1;
		else w[i] = w[i+1];
	}
	for(int i=0; i<n-1; i++) {
		cout << i+1 << " " << w[i+1] << endl;
	}
}
