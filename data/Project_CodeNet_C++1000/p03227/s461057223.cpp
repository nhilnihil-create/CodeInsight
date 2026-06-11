#include<iostream>
#include<vector>
#include<string>
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;
using namespace std;

int main() {
	string s;
	cin >> s;
	if (s.size() == 2) cout << s << endl;
	else {
		for (int i = 2; i >= 0; i--) cout << s[i];
		cout << endl;
	}
}