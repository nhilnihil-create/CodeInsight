#include "bits/stdc++.h"

using namespace std;

//using Matrix = vector< vector<int> >;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9 + 10;
//const ll INF = 1e18 + 10LL;
int dx[5] = {0, 0, 1, -1, 0}, dy[5] = {1, -1, 0, 0, 0};
const double EPS = 1e-10;
bool cmp(P a, P b) { return a.second < b.second; } //End sort (Interval scheduling problem)

int n;
string S;

ll ans;
map<pair<string, string>, ll> mp;

int main(void){
	cin>>n>>S;

	string s1 = S.substr(0, n);
	string s2 = S.substr(n);
	reverse(s2.begin(), s2.end());

	for (int i = 0; i < 1 << n; i++) {
		string r, b;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) r += s1[j];
			else b += s1[j];
		}
		mp[make_pair(r, b)]++;
	}

	for (int i = 0; i < 1 << n; i++) {
		string r, b;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) r += s2[j];
			else b += s2[j];
		}
		ans += mp[make_pair(r, b)];
	}

	printf("%lld\n", ans);
	
	return 0;
}