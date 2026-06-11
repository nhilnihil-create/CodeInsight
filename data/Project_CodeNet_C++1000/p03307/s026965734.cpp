#include <math.h>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vint;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rrep(i,j,n) for(int i = (int)(j); i < (int)(n); i++)
#define mrep(i,n) for (int i = (int)(n-1); i > 0; i--)
#define be(v) (v).begin(), (v).end()
#define scout cout << fixed << setprecision(20)
ll INF = 1LL << 60;
ll mod = 1e9 + 7;
ll MAX=1e18;

int main() {
	int n; cin >> n;
	if(n%2==0) cout << n << endl;
	else cout << n*2 << endl;
}