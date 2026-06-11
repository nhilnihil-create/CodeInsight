#include <bits/stdc++.h>
#define cout16 cout << setprecision(16) 
#define rep(i,n) for(int i=0;i<n;i++ )
#define rep2(i,f,n) for(int i=f;i<n;i++ )
#define SORT(A) sort(A.begin(),A.end())
#define REV(A) reverse(A.begin(),A.end())
typedef long long int ll;
using vi = std::vector<int>;
using vvi = std::vector<std::vector<int>>;
using vll = std::vector<ll>;
using vvll = std::vector<std::vector<ll>>;
using P = std::pair<int,int>;
using vp = std::vector<P>;
using namespace std;
#define INF 1001001001
#define LL_INF 1001001001001001001
#define fi first
#define se second

int main(void) {
	int n; cin >> n;
	vi c(n-1),s(n-1),f(n-1);
	rep(i,n-1) cin >> c[i] >> s[i] >> f[i];
	rep(i,n-1){
		int t = s[i];
		for(int j=i; j<n-1; j++){
			t = max(t,s[j]);
			t += (f[j]-(t%f[j]))%f[j];
			t += c[j];
		}
		cout << t << endl;
	}
	cout << 0 << endl;
}
