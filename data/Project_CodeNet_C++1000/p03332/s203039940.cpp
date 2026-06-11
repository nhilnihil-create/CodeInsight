///A drunk man will find his way home, but a drunk bird may get lost forever...
#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef pair <int, int> pii;
#define pb push_back
#define f first
#define s second
#define sz(x) (int)x.size()
const int mx = 3e5 + 10, m = 998244353;
int fact[mx], inv[mx];
int _pow(int a, int b){
	if(!b)
		return 1;
	return ((_pow((a * a) % m, b >> 1) * ((b & 1) ? a : 1)) % m);
}
int c(int n, int k){
	return((((fact[n] * inv[k]) % m) * inv[n - k]) % m);
}
void pre(){
	fact[0] = 1;
	for(int i = 1; i <= mx; i++)
		fact[i] = (fact[i - 1] * i) % m;
	inv[mx] = _pow(fact[mx] , m - 2);
	for(int i = mx - 1; i >= 0; i--)
		inv[i] = ((inv[i + 1] * (i + 1)) % m);
	return;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);
	pre();
	int n, a, b, k, ans = 0;
	cin >> n >> a >> b >> k;
	for(int i = 0; i <= n; i++){
		if(k - (i * a) >= 0){
			if((k - (i * a)) % b == 0 && (k - (i * a)) / b <= n){
		//		cout << i << " " << (k - (i * a)) / b << endl;
		//		cout << fact[n] << " " << inv[i] << " " << inv[n - i] << " " << c(i , n) << endl;
				ans += c(n , i) * c(n , ((k - (i * a)) / b));
				ans %= m;
	//			cout << ans << endl;
			}
		}
		else
			break;
	}
	cout << ans << endl;
	return 0;
}
