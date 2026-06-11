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
	ll ans = 0;
	int tmp;
	string s;
	ll k;
	cin >> s >> k;
	int no = s.size()+1, x;
	REP(i, s.size()){
		if(s[i]!='1'){
			no = i + 1;
			x = s[i] -'0';
			break;
		}
	}
	if(k < (ll)no) cout << 1 << endl;
	else cout << x << endl;
}