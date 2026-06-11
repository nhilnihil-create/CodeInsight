#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main()
{
	int a,b,c;
	cin >> a >> b >> c;
	int ans;
	if (a == b) ans = c;
	else if (b == c) ans = a;
	else ans = b;
	cout << ans << endl;
	return 0;
}