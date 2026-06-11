#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int INF = 0x3F3F3F3F;
const ll INFLL = 0x3F3F3F3F3F3F3F3FLL;

int main(){
	
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	
	int n, a, b;
	cin >> n >> a >> b;
	
	int d = (abs(b-a));
	
	if(d & 1) cout << "Borys\n";
	else cout << "Alice\n";
	
	return 0;
}