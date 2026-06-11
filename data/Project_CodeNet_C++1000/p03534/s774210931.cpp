#include <bits/stdc++.h>
using namespace std;

#define REP(i,s,n) for(int i=s; i<n; ++i)
#define rep(i,n) REP(i,0,n)
#define SORT(c) sort((c).begin(),(c).end())
#define IINF INT_MAX
#define LLINF LLONG_MAX
#define DEBUG false

typedef long long ll;
typedef pair<int, int> ii;

int main(){

	string s;
	cin >> s;
	vector<int> cnt(3, 0);

	rep(i, s.size()) cnt[s[i] - 'a']++;
	if(abs(cnt[0] - cnt[1]) <= 1 && abs(cnt[1] - cnt[2]) <= 1 && abs(cnt[0] - cnt[2]) <= 1) cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;
}
