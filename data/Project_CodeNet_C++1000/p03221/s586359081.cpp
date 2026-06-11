//高知能系Vtuberの高井茅乃です。
//Twitter: https://twitter.com/takaichino
//YouTube: https://www.youtube.com/channel/UCTOxnI3eOI_o1HRgzq-LEZw

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define INTINF 1999999999
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define MODA 1000000007 

int main() {
	int ans = 0;
	int tmp;
	vector< tuple < int, int, int, int> > dt;
	dt.push_back(make_tuple(0, 0, 0, 0));
	int n, m;
	cin >> n >> m;
	int p, y;
	REP1(i, m){
		cin >> p >> y;
		dt.push_back(make_tuple(p, y, i, 0));
	}
	sort(dt.begin(), dt.end());
	int prep, preno, nowp, ind;
	vector< pair <int, int>> id(m+1);
	id[0] = make_pair(0,0);
	REP1(i, m){
		tie(prep, ignore, ignore, preno) = dt[i-1];
		tie(nowp, ignore, ind, ignore) = dt[i];
		if(nowp == prep){
			dt[i] = make_tuple(nowp, 0, ind, preno + 1);
			id[ind] = make_pair(nowp, preno+1);
		}
		else {
			dt[i] = make_tuple(nowp, 0, ind, 1);
			id[ind] = make_pair(nowp, 1);
		}
	}
	REP1(i, m) printf("%06d%06d\n", id[i].first, id[i].second);
	//cout << ans << endl;
}