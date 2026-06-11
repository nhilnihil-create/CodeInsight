#include <iostream>
#include <set>
#include <string>
#define llint long long

using namespace std;

llint h, w, n;
llint x, y;
llint l, r, u, d;
string s, t;

int main(void)
{
	cin >> h >> w >> n;
	cin >> y >> x;
	cin >> s >> t;
	s = "#" + s, t = "#" + t;
	
	l = 1, r = w, u = 1, d = h;
	for(int i = n; i >= 1; i--){
		if(t[i] == 'L') r = min(w, r+1);
		if(t[i] == 'R') l = max(1LL, l-1);
		if(t[i] == 'U') d = min(h, d+1);
		if(t[i] == 'D') u = max(1LL, u-1);
		if(l > r || u > d){
			cout << "NO" << endl;
			return 0;
		}
		if(s[i] == 'L') l++;
		if(s[i] == 'R') r--;
		if(s[i] == 'U') u++;
		if(s[i] == 'D') d--;
		if(l > r || u > d){
			cout << "NO" << endl;
			return 0;
		}
	}
	if(x >= l && x <= r && y >= u && y <= d) cout << "YES" << endl;
	else cout << "NO" << endl;
	
	return 0;
}