#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	int n = (int) s.size();
	stack<int> st;
	int ans = 0;
	for(int i = 0; i < n; i++) {
		if(st.size() && st.top() != s[i]) {
			st.pop();
			ans++;
		} else {
			st.push(s[i]);
		}
	}
	cout << ans * 2 << endl;
}