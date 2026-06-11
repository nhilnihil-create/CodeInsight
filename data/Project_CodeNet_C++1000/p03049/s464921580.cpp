#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
int main(){
	int n;
	cin >> n;
	int ans = 0;
	int ea = 0;
	int sb = 0;
	int ba = 0;
	rep(i, n){
		string s;
		cin >> s;
		rep(j, s.size()-1){
			if(s.at(j) == 'A' && s.at(j+1) == 'B') ans++;
		}
		if(s.at(s.size()-1) == 'A' && s.at(0) == 'B') ba++;
		else if(s.at(s.size()-1) == 'A') ea++;
		else if(s.at(0) == 'B') sb++;
	}
	int mi = min(ea, sb);
	int ma = max(ea, sb);
	ans += mi;
	if(ma == 0 && ba != 0) ba--;
	ans += ba;
	cout << ans << endl;
	return 0;
}