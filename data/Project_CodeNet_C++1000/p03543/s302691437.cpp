using namespace std; 
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include<set>
#define vi vector<int>
#define vc vector<char>
 
int main() {
	string s; cin >> s; 
	int ans = 0 , mx=1;
	for (int i = 1; i < 4; i++) {
		if (s[i] == s[i - 1]) mx++; 
		else {
			ans = max(ans, mx); 
			mx = 1; 
		}
		if (i == 3) {
			ans = max(mx, ans); 
		}
	}
	if (ans >= 3) cout << "Yes";
	else cout << "No"; 
}