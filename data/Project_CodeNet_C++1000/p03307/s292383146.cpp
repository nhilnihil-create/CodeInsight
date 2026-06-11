#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
typedef long long ll;

int main(){
	ll n;
	cin >> n;
	ll ans = n * 2 / __gcd(n,ll(2));
	cout << ans << endl;
    return 0;
}

