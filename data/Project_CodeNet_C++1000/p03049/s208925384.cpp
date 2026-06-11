#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
using ll=long long;
using pll=pair<ll,ll>;
 
#define fi first
#define se second
#define pb push_back
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define MOD 1000000007
 
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
 
int main() {
	int N;
	cin >> N;
	vector<string> S(N);
	ll ans = 0, counta = 0, countb = 0, countab=0;
	rep(i,N) {
		cin >> S[i];
		int n = S[i].length();
		if(S[i][0] == 'B') countb++;
		if(S[i][n-1] == 'A') counta++;
		if(S[i][0] == 'B' && S[i][n-1] == 'A') countab++;
	}
	rep(i,N) rep(j,S[i].length()-1) {
		if(S[i][j] == 'A' && S[i][j+1] == 'B') ans++;
	}
	ans += min(counta, countb);
	if(countab != 0 && countab == counta && countab == countb) ans -= 1;
	cout << ans << endl;
 
 
  return 0;
}