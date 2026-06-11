#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#include<math.h>

using namespace std;

#define INF 1000000007
#define LINF (1LL << 62)

typedef long long i64;
typedef pair<i64,i64> P;


int n;
string s;
i64 a[101010], b[101010], c[101010], d[101010];

i64 mod_pow(i64 x, i64 y, i64 mod){
	i64 res = 1;
	while(y > 0){
		if(y & 1) res = res * x % mod;
		x = x*x %mod;
		y >>= 1;
	}
	return res;
}

int main(){
	cin >> s;
	n = s.size();
	
	i64 ans = 0;
	for(int i = 0; i < n; i++){
		d[i+1] = d[i];
		a[i+1] = a[i];
		b[i+1] = b[i];
		c[i+1] = c[i];
		if(s[i] == '?') d[i+1]++;
		if(s[i] == 'A') a[i+1]++;
		if(s[i] == 'B') b[i+1]++;
		if(s[i] == 'C') c[i+1]++;
	}
	//Bの位置から計算
	for(int i = 1; i < n; i++){
		if(s[i] == 'B'){
			ans += a[i] * (c[n] - c[i]) % INF * mod_pow(3,d[n],INF);
			ans %= INF;
			ans += a[i] * (d[n] - d[i]) % INF * mod_pow(3,d[n]-1,INF);
			ans %= INF;
			ans += d[i] * (c[n] - c[i]) % INF * mod_pow(3,d[n]-1,INF);
			ans %= INF;
			ans += d[i] * (d[n] - d[i]) % INF * mod_pow(3,d[n]-2,INF);
			ans %= INF;
		}
		if(s[i] == '?'){
			ans += a[i] * (c[n] - c[i]) % INF * mod_pow(3,d[n]-1,INF);
			ans %= INF;
			ans += a[i] * (d[n] - d[i]-1) % INF * mod_pow(3,d[n]-2,INF);
			ans %= INF;
			ans += d[i] * (c[n] - c[i]) % INF * mod_pow(3,d[n]-2,INF);
			ans %= INF;
			ans += d[i] * (d[n] - d[i]-1) % INF * mod_pow(3,d[n]-3,INF);
			ans %= INF;
		}
	}
	cout << ans << endl;
	
	return 0;
}