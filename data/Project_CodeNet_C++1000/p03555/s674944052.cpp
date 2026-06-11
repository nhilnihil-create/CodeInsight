#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int INF = 1e9 + 10;
const ll INFLL = 3e18;

int main(){
	
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	
	string s, t;
	cin >> s;
	cin >> t;
	
	reverse(t.begin(), t.end());
	if(t == s) cout << "YES\n";
	else cout << "NO\n";
	
	return 0;
}