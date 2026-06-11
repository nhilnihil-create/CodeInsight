#include<bits/stdc++.h>
using namespace std;

int main(){
	string s;
	int a;
	cin >> s >> a;
	string ans = "";
	for(int i = 0; i < s.size(); i+=a){
		char c = s[i];
		ans += c;
	}
	cout << ans << endl;
	return 0;
}