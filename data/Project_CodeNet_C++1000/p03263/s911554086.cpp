//高知能系Vtuberの高井茅乃です。
//Twitter: https://twitter.com/takaichino
//YouTube: https://www.youtube.com/channel/UCTOxnI3eOI_o1HRgzq-LEZw

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define INF 1999999999
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define MODA 1000000007 

int main() {
	int ans = 0;
	int tmp;
	int h, w;
	cin >> h >> w;
	int mt[h][w];
	REP(i, h) REP(j, w) cin >> mt[i][j];
	vector<tuple <int, int, int, int> > ls;
	int nu = 0;
	REP(i, h){
		REP(j, w-1){
			if(mt[i][j] % 2 == 1){
				mt[i][j] --;
				mt[i][j+1]++;
				ls.push_back(make_tuple(i+1, j+1, i+1, j+2));
				nu ++;
			}
		}
	}
	REP(i, h-1){
		if(mt[i][w-1] % 2 == 1){
			mt[i][w-1] --;
			mt[i+1][w-1]++;
			ls.push_back(make_tuple(i+1, w, i+2, w));
			nu ++;
		}
	}
	cout << nu << endl;
	REP(i, nu){
		int aa, bb, cc, dd;
		tie(aa, bb, cc, dd) = ls[i];
		cout << aa << " " <<bb << " " << cc << " " << dd << endl;
	}
}