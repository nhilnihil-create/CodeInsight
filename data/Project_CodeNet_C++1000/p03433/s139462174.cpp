#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define ll long long
#define rep(i,n) for (ll i = 0; i < (ll)(n); ++i)
#define be(v) (v).begin(), (v).end()
#define dcout cout << fixed << setprecision(20) 
ll INF = 1LL << 60;
ll mod = 1e9 + 7;

int main() {
	int n,m; cin >> n >> m;
	n%=500;
	if(n<=m) cout << "Yes" << endl;
	else cout << "No" << endl;
}