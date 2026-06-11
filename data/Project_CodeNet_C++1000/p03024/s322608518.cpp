#include <bits/stdc++.h>

using namespace std;
using ll = long long;

//container util
#define SORT(c) sort((c).begin(),(c).end())
#define all(a) (a).begin(), (a).end()

//repetition
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

//print
#define pv(val) cerr << #val << '=' << (val) << endl

const int INF = 1e9;

int main(void){

	string S; cin >> S;

	int ans = 0;
	REP(i,S.length()){
		if(S[i] == 'o') ans++;
	}
	ans += 15 - S.length();



	if(ans > 7) cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;

}
