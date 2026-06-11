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
	string s, t;
	cin >> s >> t;
	int st[26], tt[26];
	REP(i, 26){
		st[i] = -1;
		tt[i] = -1;
	}
	tmp = 0;
	REP(i, s.size()){
		if(st[s[i] - 'a'] == -1){
			st[s[i] - 'a'] = tmp;
			tmp++;
		}
		s[i] = st[s[i] - 'a'] + 'a';
	}
	tmp = 0;
	REP(i, t.size()){
		if(tt[t[i] - 'a'] == -1){
			tt[t[i] - 'a'] = tmp;
			tmp++;
		}
		t[i] = tt[t[i] - 'a'] + 'a';
	}
	if (s == t) cout << "Yes" << endl;
	else cout << "No" << endl;
	
	//cout << ans << endl;
}