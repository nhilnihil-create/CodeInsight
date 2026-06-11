#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 25;
const int MOD = 1e9+7;
string dic[100003];
int a=0, b=0, ab=0;
int main() {
	int n;
	cin >> n;
	rep(i,n) cin >> dic[i];
	int ans = 0;
	rep(i,n) {
		string s = dic[i];
		if (s[0] == 'B' && s[s.size()-1] == 'A') ab++;
		if (s[0] != 'B' && s[s.size()-1] == 'A') b++;
		if (s[0] == 'B' && s[s.size()-1] != 'A') a++;
		for (int i = 0; i < s.size()-1; i++)
		{
			if (s[i]=='A' && s[i+1] == 'B') ans++;
		}	
	}
	if (ab==0) ans += min(a,b);
	if (ab > 0 && a+b==0) ans += ab-1;
	if (ab>0 && a+b > 0) ans += (ab + min(a,b));
	cout << ans << endl;
	
	return 0;
}