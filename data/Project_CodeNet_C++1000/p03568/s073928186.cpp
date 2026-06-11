#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
typedef long long ll;

int main(){
	int n;
	cin >> n;
	ll ans = 1;
	ll even = 0;
	rep(i,n){
		int a;
		cin >> a;
		if(a%2==0) even++;
	}
	ll temp = 1;
	rep(i,even) temp *= 2;
	rep(i,n) ans *= 3;
	ans -= temp;
	cout << ans << endl;
    return 0;
}

