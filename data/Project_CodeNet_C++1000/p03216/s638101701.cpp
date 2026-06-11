#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
const int MX = 1000005;
int n, q, k, a[MX], b[MX];
string s;
int main(){
	cin >> n >> s >> q;
	rep(i,n){
		a[i+1] = a[i] + (s[i] == 'D');
		b[i+1] = b[i] + (s[i] == 'M');
	}
	rep(i,q){
		cin >> k;
		long long t = 0, ans = 0;
		rep(j,n){
			if(j-k >= 0 && s[j-k] == 'D') t -= b[j] - b[j-k];
			if(s[j] == 'M') t += a[j] - (j-k >= 0 ? a[j-k+1] : 0);
			else if(s[j] == 'C') ans += t;
		}
		cout << ans << '\n';
	}
}