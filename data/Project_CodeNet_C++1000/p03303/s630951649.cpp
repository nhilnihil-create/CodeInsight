#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<math.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;
int main() {
	string s;
	cin >> s;
	int w;
	cin >> w;
	int len = s.size() / w;
	string ans;
	if (s.size() % w == 0) {
		for (int i = 0; i < w * len; i += w) {
			ans += s[i];
		}
	}
	else {
		for (int i = 0; i <= w * len; i += w) {
			ans += s[i];
		}
	}
	cout << ans << endl;
	
	return 0;
}