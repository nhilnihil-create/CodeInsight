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
	int ans = INTINF;
	int tmp;
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	vector<int > l;
	REP(i, n) {
		cin >> tmp;
		l.push_back(tmp);
	}
	int aa, bb, cc;
	REP(i, 1 << (2*n)){
		aa = 0;
		bb = 0;
		cc = 0;
		tmp = 0;
		REP(j, n){
			int v = ((i >>(2*j)) & 3);
			if(v == 0){
				if(aa != 0) tmp += 10;
				aa += l[j];
			}
			if(v == 1){
				if(bb != 0) tmp += 10;
				bb += l[j];
			}
			if(v == 2){
				if(cc != 0) tmp += 10;
				cc += l[j];
			}
		}
		if(!(aa && bb && cc)) continue;
		tmp += abs(aa - a);
		tmp += abs(bb - b);
		tmp += abs(cc - c);
		ans = min(tmp, ans);
	}
	cout << ans << endl;
}