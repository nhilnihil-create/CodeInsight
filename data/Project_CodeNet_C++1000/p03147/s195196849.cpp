#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;
ll gcd(ll a, ll b) {
   if (a%b == 0) return(b);
   else return(gcd(b, a%b));
}

int main(){
	int N;
	cin >> N;
	int h[N];
	int tot = 0;
	rep(i,N) {
		int x;
		cin >> x;
		h[i] = -x;
		tot += x;
	}

	int ans = 0;
	while (tot > 0) {
		int l = 0;
		while (l < N) {
			if (h[l] < 0) {ans++; break;}
			l++;
		}
		int r = l;
		while (r < N) {
			if (h[r] < 0) {tot--; h[r]++;}
			else break;
			r++;
		}
	}
	cout << abs(ans) << endl;
return 0;
}
