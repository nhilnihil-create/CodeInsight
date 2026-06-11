#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

int main() {
	string s,ans;
	int w;
	cin >> s;
	cin >> w;

	for (int i=0;w <= s.size();i++) {
		if ((i * w) >= s.size())break;
		ans += s[i * w];
	}
	cout << ans << endl;
}
