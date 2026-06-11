#include <bits/stdc++.h>
using namespace std;
 
 
 
string str;
 
void solve() {
	cin >> str;
	int a[3] = {0};
	for (int i = 0; i < str.length(); i++) {
		a[str[i] - 'a']++;
	}
 
	if ((*max_element(a, a + 3) - *min_element(a, a + 3)) <= 1) {
		puts("YES");
	} else {
		puts("NO");
	}
}
 
int main() {

	solve();
}