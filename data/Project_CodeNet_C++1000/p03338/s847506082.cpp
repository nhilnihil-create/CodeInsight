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
	int n;cin >> n;
	string s;cin >> s;
	int ans = 0;
	for(int i = 1;i < n - 1;i ++)
	{
		string l = s.substr(0, i);
		string r = s.substr(i , n - i);
		vector<bool> vis(100 , 0);
		int cnt = 0;
		for(int i = 0;i < l.size();i ++)
			vis[l[i] - 'a'] = 1;
		for(int i = 0;i < r.size();i ++)
			if(vis[r[i] - 'a']){
				cnt++;
				vis[r[i] - 'a'] = 0;
			}
		ans = max(cnt , ans);
	}	
	cout << ans << endl;
}
int main()
{
	SIS;
	slove();
}