#include <bits/stdc++.h>

using namespace std;

#define REP(i,n) for(int i=0; i<int(n); i++)
#define FOR(i,m,n) for(int i=int(m); i<int(n); i++)
#define ALL(obj) (obj).begin(),(obj).end()
#define VI vector<int>
#define VLL vector<long long>
#define VVI vector<vector<int>>
#define VVLL vector<vector<long long>>
#define VC vector<char>
#define VS vector<string>
#define VVS vector<vector<string>>
#define VVC vector<vector<char>>
#define fore(i,a) for(auto &i:a)
typedef long long ll;
typedef pair <int, int> P;
const int  INF = 2147483647;
const ll INFL = 9223372036854775807;
const ll mod = 1000000007;

using namespace std;



int main() {
	string s;
	cin >> s;
	int a, b, c;
	a = b = c = 0;
	REP(i, s.size()) {
		if (s[i] == 'a')a++;
		else if (s[i] == 'b')b++;
		else c++;
	}
	if (max({ a,b,c }) - min({ a,b,c }) <= 1)cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}