#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(n) begin(n), end(n)
using ll = long long;
using namespace std;

void tr_vc(vector<int> &tsx, vector<int> &tsy, string s, int n){
	rep(i, n){
		if(s[i] == 'L'){
			tsx.at(i) = -1;
			tsy.at(i) = 0;
		}else if(s[i] == 'R'){
			tsx.at(i) = 1;
			tsy.at(i) = 0;
		}else if(s[i] == 'U'){
			tsx.at(i) = 0;
			tsy.at(i) = -1;
		}else{
			tsx.at(i) = 0;
			tsy.at(i) = 1;
		}
	}
}

bool fc(vector<int> &s, vector<int> &t, int p, int li, int n){
	int li0 = 1, limx = li;
	rrep(i, n){
		// cerr << t.at(i) << " " << s.at(i) << " ";
		if(t.at(i) == -1){
			limx = min(li, limx+1);
		}else if(t.at(i) == 1){
			li0 = max(1, li0-1);
		}

		if(s.at(i) == -1){
			li0++;
		}else if(s.at(i) == 1){
			limx--;
		}
		if(limx < li0) return true;
		// cerr << li0 << " " << limx << " " << p << endl;
	}
	if(p < li0 || limx < p) return true;
	return false;
}

int main(){
	int h, w, n;
	cin >> h >> w >> n;
	int py, px;
	cin >> py >> px;
	string s, t;
	cin>> s >> t;
	vector<int> tsx(n), tsy(n), ttx(n), tty(n);
	tr_vc(tsx, tsy, s, n);
	tr_vc(ttx, tty, t, n);
	bool ans;
	ans = fc(tsx, ttx, px, w, n);
	// cerr << endl;
	ans = ans || fc(tsy, tty, py, h, n);
	if(ans) cout << "NO" << endl;
	else cout << "YES" << endl;
	
	return 0;
}