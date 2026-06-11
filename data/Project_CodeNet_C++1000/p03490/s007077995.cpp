/*
ID: darynbo2
TASK: ride
LANG: C++14                 
*/
#include<bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define all(s) s.begin(),s.end()
#define ld long double

using namespace std;

const int maxn = 1e5 + 7;
const ld eps = 1e-6;
const ll inf = 1e9 + 7;

string s;
int x, y;
int curx = 0, cury = 0;
int dir = 1;
vector<int> vec;      
map<int,int> dp1,dp2,dp3,dp4;

int main() {
	cin >> s;
	cin >> x >> y;
	int cur = 0;          
	s.pb('T');
	bool check = 1;
	bool p = 0;
	       
	vector<int>fir,sec;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'T') {
			if (check) {
				x-=cur;
				cur = 0;
				check = 0;
			}
			else {
				if (!p)fir.pb(cur);
				else sec.pb(cur);
				cur = 0;
				p ^= 1;
			}
		}
		else cur++;
	}                  
	sort (fir.begin(), fir.end());
	reverse (fir.begin(), fir.end());
	sort (sec.begin(), sec.end());
	reverse (sec.begin(), sec.end());
	for (int i = 0; i < fir.size(); i++) {
		if (abs(y + fir[i]) > abs(y - fir[i])) y-=fir[i];
		else y+=fir[i];
	}
	for (int i = 0; i < sec.size(); i++) {
		if (abs(x + sec[i]) > abs(x - sec[i])) x-=sec[i];
		else x+=sec[i];
	}
	if (x == 0 && y == 0) cout << "Yes";
	else cout << "No";
	return 0;
}
