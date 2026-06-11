#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
using P = pair<int,int>;
using pq = priority_queue<int>;
typedef long long ll;

int  main()
{
	string s,t; cin >> s >> t;
	sort(s.begin(), s.end());
	sort(t.rbegin(), t.rend());
	if (s < t)
		cout << "Yes\n";
	else
		cout << "No\n";
	return (0);
}