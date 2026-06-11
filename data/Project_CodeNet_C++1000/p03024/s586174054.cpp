//khodaya khodet komak kon
#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define all(x) x.begin(), x.end()
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")


using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 200000 + 10;
const ll MOD = 1000000000 + 7;
const ll INF = 1000000010;
const ll LOG = 25;

int n;
string s;

int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> s;
	n = s.size();
	int sm = 15 - n;
	for (auto u:s) if (u == 'o') sm++;
	cout << (sm >= 8?"YES":"NO");












	return 0;
}
