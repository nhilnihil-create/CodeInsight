#include <bits/stdc++.h>

#define SIS std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define lowbit(x) (x & -x)
#define PI 3.14159265358979323846264338327950L
typedef long long ll;
using namespace std;
const int MAX = 0x7ffffff;
int t;

void slove()
{
	string s;
	cin >> s;
	int n = s.size();
	vector<int> sum(n + 1);
	sum[0] = (s[0] == 'B');
	for(int i = 1;i < s.size();i ++){
		sum[i] = sum[i-1] + (s[i] == 'B');
	}
	ll ans = 0;
	for(int i = s.size() ;i >= 0;i --)
	{
		if(s[i] == 'W')
			ans += sum[i];
	}
	cout << ans << endl;
}
int main()
{
	SIS;
	slove();
}