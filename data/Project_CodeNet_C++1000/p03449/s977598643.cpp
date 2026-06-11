#include<bits/stdc++.h>
// Begin Header {{{
#define all(x) (x).begin(), (x).end()
#define lli long long int
#define rep(i,n) for(lli i=0; i<n; i++)
#define loop(i, j, n) for(lli i=j; i<n; i++)
#define Max(a, b) ((a) > (b) ? (a) : (b))
#define Min(a, b) ((a) < (b) ? (a) : (b))
constexpr int INF  = 0x3f3f3f3f;
const long long mod=1e9+7;
const double PI = acos(-1);
//Function
lli combi(lli n, lli r){
	if(r==0 || r==n) return 1;
	else return combi(n-1,r) + combi(n-1,r-1);
}
lli sigma1(lli n){return n*(n+1)/2;}
lli sigma2(lli s, lli n){return sigma1(n) - sigma1(s -1);}
using namespace std;
// }}} End Header

int main() {
	int n;
	cin >> n;
	vector<vector<int>> a(2, vector<int>(n));
	rep(i,2){
		rep(j,n){
			cin >> a[i][j];
		}
	}
	int max  = 0;
	rep(i,n){
		int sum = 0;
		rep(j,i+1) sum += a[0][j];
		loop(k, i, n) sum+= a[1][k];
		max =Max(max, sum);
	}
	cout << max << endl;
	return 0;
}