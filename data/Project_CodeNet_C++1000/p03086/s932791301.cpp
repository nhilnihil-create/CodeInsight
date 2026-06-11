#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int N = 2e5 + 100;
string s;
int ans = 0;
int main() {
	
	cin >> s;
	
	int tmp = 0;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == 'A' || s[i] == 'C' || s[i] == 'G' || s[i] == 'T') {
			tmp++;
			ans = max(ans, tmp);
		}else tmp = 0;
	}
	
	cout << ans << endl;
	return 0;	
} 