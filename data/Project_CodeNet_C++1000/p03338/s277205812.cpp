#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	string s;
	cin >> n >> s;

	int res = 0;
	for (int i = 0; i < n - 1; i++)
	{
		int cnt = 0;
		for (int j = 0; j < 26; j++)
		{
			char ch = 'a' + j;
			bool x = false, y = false;
			for (int k = 0; k < n; k++)
			{
				if(s[k] == ch) {
					if(k <= i) x = true;
					else y = true;
				}
			}
			if(x && y) cnt++;
		}
		res = max(res, cnt);
	}
	cout << res << endl;
	return 0;
}
