#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define sz size()
#define mp make_pair
#define pii pair<int,int>

const ll mod = 1e9+7;

int main()
{
	string s;
	int w;
	cin >> s;
	cin >> w;

	string ans;

	for(int i = 0;i < s.sz;i+=w)ans += s[i];

	cout << ans << endl;

	return 0;
}