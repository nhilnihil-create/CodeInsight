#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
using namespace std;
using P = pair<int,int>;
typedef long long ll;

int  main()
{
	string s;
	cin >> s;
	set<char> st;
	rep(i, 3)
		st.insert(s[i]);
	if (st.size() == 3)
		cout << "Yes\n";
	else 
		cout << "No\n";

	return (0);
}