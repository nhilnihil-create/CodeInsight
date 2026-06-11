#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,n) for(int i=(a); i<(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int main() {
	int N; cin >> N;
	for(ll h=1LL; h<=3500LL; h++) for(ll n=1LL; n<=3500LL; n++) {
		if ((4LL*h*n-n*N-h*N)!=0 && (h*n*N)%(4LL*h*n-n*N-h*N)==0LL && (4*h*n-n*N-h*N)>0LL) {
			cout << h << " " << n << " " << (h*n*N)/(4LL*h*n-n*N-h*N) << endl;
			return 0;
		}
	}
}