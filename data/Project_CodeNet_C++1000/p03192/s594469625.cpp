#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;

int main() {
	string s;
	cin >> s;
	int cnt = 0;
	rep(i, 4) {
		if (s[i] == '2') cnt++;
	}
	cout << cnt << endl;
	return 0;
}