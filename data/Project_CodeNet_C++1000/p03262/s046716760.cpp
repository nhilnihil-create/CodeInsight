#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;
ll gcd(ll a, ll b) {
   if (a%b == 0) return(b);
   else return(gcd(b, a%b));
}

int main(){
	int N, X;
	cin >> N >> X;
	int x[N];

	rep(i,N) {
		int y;
		cin >> y;
		x[i] = y-X;
	}

	int ans = 0;
	rep(i,N) ans = gcd(ans,x[i]);
	cout << abs(ans) << endl;
return 0;
}
