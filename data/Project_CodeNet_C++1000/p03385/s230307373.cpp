#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	set<char> st;
	string s;
	cin >> s;
	st.insert(s[0]);
	st.insert(s[1]);
	st.insert(s[2]);
	if (st.size() == 3)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}

