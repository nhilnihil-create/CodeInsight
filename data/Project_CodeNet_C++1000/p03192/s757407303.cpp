#include <bits/stdc++.h>
#define rep(i,n) for(int i=(0);i<(n);i++)

using namespace std;

typedef long long ll;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	string s;
	cin >> s;
	int n = s.size();
	
	int cnt = 0;
	rep(i, n) if(s[i] == '2') cnt++;
	cout << cnt << endl;

}
