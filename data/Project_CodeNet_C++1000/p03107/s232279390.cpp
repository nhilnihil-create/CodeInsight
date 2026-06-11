#include<bits/stdc++.h>
using namespace std;

int main() {
	string s; cin >> s;
	queue<char> que;
	que.push(s[0]);
	int res = 0;
	for (int i = 1; i < s.size(); i++)
	{
		if(que.empty()) que.push(s[i]);
		else if(s[i] == que.back()) que.push(s[i]);
		else {
			res += 2;
			que.pop();
		}
	}
	cout << res << endl;
	return 0;
}
