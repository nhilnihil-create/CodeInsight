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
	char a[3][3];
	rep(i,3)rep(j,3) cin >> a[i][j];
	cout << a[0][0] << a[1][1] << a[2][2] << endl;
}