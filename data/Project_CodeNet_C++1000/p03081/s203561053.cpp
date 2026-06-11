#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9;
const long long LINF = 1e18;
const long long MOD = 1e9 + 7;

signed main(){
	int n,q;
	cin >> n >> q;
	string s;
	cin >> s;
	char t[q],d[q];
	rep(i,q){
		cin >> t[i] >> d[i];
	}
	int left = 0, right = n;
	for(int i = q - 1; i >= 0; i--){
		if(t[i] == s[left] && d[i] == 'L') left++;
		if(t[i] == s[right - 1] && d[i] == 'R') right--;
		if(left > 0 && t[i] == s[left - 1] && d[i] == 'R') left--;
		if(right < n && t[i] == s[right] && d[i] == 'L') right++;
	}
	cout << max(0, right - left) << endl;
	return 0;
}