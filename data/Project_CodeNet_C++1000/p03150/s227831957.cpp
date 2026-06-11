#include<bits/stdc++.h>
using namespace std;
string s;
int main() {
	cin>>s;
	int n = s.size();
	int len = n - 7;
	for(int i = 0; i <= 7; i++) {
		string t = "";
		for(int j = 0; j < i; j++) {
			t += s[j];
		}
		for(int j = i + len; j < n; j++) {
			t += s[j];
		}
//		cout<<t<<endl;
		if(t == "keyence") {
			cout<<"YES"<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
	return 0;
}
/*
keyofscience
Output:YES

mpyszsbznf
Output:NO

ashlfyha
Output:NO

keyence
Output:YES

keyencejerrydream
Output:YES

jerrydreamkeyence
Output:YES
*/