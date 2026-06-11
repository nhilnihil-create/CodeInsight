#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
typedef long long ll;
typedef pair<int, int> PI;
typedef pair<ll, ll> PL;

const ll mod = 1000000007;


int main() {
	cin.tie(0);
   	ios::sync_with_stdio(false);
	int a, b; cin >> a >> b;
	if(a >= 13) cout << b;
	else if(6 <= a && a <= 12) cout << b/2;
	else cout << 0;
} 