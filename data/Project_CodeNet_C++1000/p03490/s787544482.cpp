#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
const ull mod = 1e9 + 7;
#define REP(i,n) for(int i=0;i<(int)n;++i)

int main(){
	string s;
	int x, y;
	cin >> s >> x >> y;
	vector<int> xdir, ydir;
	bool mode = true;
	int count = 0;
	REP(i, s.size()){
		if(s[i]=='T'){
			if (count>0){
				if(mode){
					xdir.push_back(count);
				}else{
					ydir.push_back(count);
				}
			}
			count = 0;
			mode = !mode;
		}else{
			count++;
		}
	}
	if (count>0){
		if(mode){
			xdir.push_back(count);
		}else{
			ydir.push_back(count);
		}
	}

	bool exc = false;
	if(s[0]=='T') exc = true;

	bool DP[2][160001];

	REP(i, 160001){
		DP[0][i] = false;
	}
	DP[0][8000] = true;
	REP(i, xdir.size()){
		if(xdir.size()==0) break;
		if(i==0 && !exc){
			REP(j, 160001) DP[1][j] = false;
			DP[1][xdir[0]+8000] = true;
		}else{
			REP(j, 160001){
				bool flag1, flag2;
				if(j-xdir[i]>-1){
					flag1 = DP[i%2][j-xdir[i]];
				}else{
					flag1 = false;
				}
				if(j+xdir[i]<160001){
					flag2 = DP[i%2][j+xdir[i]];
				}else{
					flag2 = false;
				}
				DP[(i+1)%2][j] = (flag1 || flag2);
			}
		}
		/*
		REP(i, 11){
			cout << DP[0][7995+i] << " ";
		}
		cout << endl;
		REP(i, 11){
			cout << DP[1][7995+i] << " ";
		}
		cout << endl << endl;
		*/
	}

	bool res1 = DP[(xdir.size())%2][x+8000];

	REP(i, 160001){
		DP[0][i] = false;
	}
	DP[0][8000] = true;
	REP(i, ydir.size()){
		if(ydir.size()==0) break;
		REP(j, 160001){
			bool flag1, flag2;
			if(j-ydir[i]>-1){
				flag1 = DP[i%2][j-ydir[i]];
			}else{
				flag1 = false;
			}
			if(j+ydir[i]<160001){
				flag2 = DP[i%2][j+ydir[i]];
			}else{
				flag2 = false;
			}
			DP[(i+1)%2][j] = (flag1 || flag2);
		}
	}
	bool res2 = DP[(ydir.size())%2][y+8000];


	cout << ((res1 && res2) ? "Yes" : "No") << endl;
    return 0;
}