#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// 回文ならばtrueを返す関数
bool Get_is_palindrome(string s) {
	bool result = true;
	for (int i = 0; i < s.size() / 2; i++) {
		if (s[i] != s[s.size() - i - 1]) {
			result = false;
		}
	}
	return result;
}

int main() {
	
	int a, b; cin >> a >> b;
	int ans = 0;
	for (int i = a; i <= b; i++) {
		if (Get_is_palindrome(to_string(i))) ans++;
	}
	cout << ans << endl;
    return 0;
}