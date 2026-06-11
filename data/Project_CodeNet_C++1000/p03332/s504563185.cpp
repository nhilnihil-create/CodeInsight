#include<iostream>
#include<cstring>
#include<cstdio>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<cmath>
#include<fstream>
#include<iomanip>
#include<unordered_set>
using namespace std;
typedef long long ll;
typedef unsigned long long ull; 
const ll mod = 998244353;
const ll N = 3 * 100000 + 5;
ll Mode(ll a, ll b){
	ll sum = 1;
	while (b) {
		if (b & 1) {
			sum = (sum * a) % mod;
			b--;
		}
		b /= 2;
		a = a * a % mod;
	}
	return sum;
}
//快速幂取模 

ll inv(ll a){
	return Mode(a, mod - 2);
}
//逆元 

ll jc[N];
void init() //预处理算阶乘
{
    jc[0] = 1;
    for(int i = 1; i < N; ++i)
    jc[i] = jc[i-1] * i % mod;
}
ll C(ll n, ll m){
    if(n<0||m>n)
        return 0;
    return ((jc[n] % mod) * ((inv(jc[m]) * inv(jc[n - m])) % mod)) % mod;
}//组合数 
int main(){
//	ios::sync_with_stdio(false);
//	ifstream cin("data.txt");
//	freopen("data.txt", "r", stdin);
	init();
	ll n, a, b, k;
	ll ans = 0;
	cin >> n >> a >> b >> k;
	if(k == 0){
		cout << 1 << endl;
		return 0;
	}
	for(ll i = 0; i <= n; i++){	
		if(!((k - a * i) % b)){
			ll t1 = i;
			ll t2 = ((k - a * i) / b); 
			if(t2 < 0)continue;
			ll cnt = C(n, t1);
			cnt %= mod;
			cnt *= C(n, t2);
			cnt %= mod; 
			ans += cnt;
			ans %= mod;
		}
	}
	cout << ans << endl;
	return 0;
}