#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define int long long
using namespace std;
int n, p, ans = 1, cnt;
int jl[10000009];
int prime[10000009], isp[10000009];
template <typename T>inline void in(T &x){
	T ch = getchar(), f = 1; x = 0;
	while(!isdigit(ch)) f = ch == '-' ? -1 : f, ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	x *= f;
}
int cal(int x, int y){
	int z = 1;
	while(y){
		if(y & 1) {
//			if(z > 2147483647 && x > 2147483647)
//				return -1;
			z *= x;
		}
//		if(x > 2147483647) return -1;
		x *= x;
		y >>= 1;
//		if(z <= 0) return -1;
	}
	return z;
}
void pre(){
	for(int i = 2; i <= ceil(sqrt(p)); i++){
		if(!isp[i]){
			isp[i] = i;
			prime[++cnt] = i;
		}
		for(int j = 1; j <= cnt; j++){
			if(prime[j] > isp[i] || i * prime[j] > ceil(sqrt(p))) break;
			isp[i*prime[j]] = prime[j];
		}
	}
}
signed main(){
	in(n), in(p);
	if(n == 1){
		cout<<p;
		return 0;
	}
	pre();//int i = 2;
//	while(1){
		for(int i = 1; i <= cnt; i++){
		//	cout<<prime[i]<<" "<<p<<endl;
			if(p < prime[i]) break;
			if(p % prime[i])
				continue;
			while(!(p % prime[i]))
				jl[i]++, p /= prime[i];
			ans *= cal(prime[i], jl[i] / n);
		//	if(p == 1) break;
		//	p /= i;
	//		i = 1;
		}
//		int x = cal(i, n);
//		cout<<i<<" "<<x<<endl;
//		if(x > p || x <= 0) break;
//		if(p % x){
//			i++;
//			continue;
//		}
//		ans *= i;
//		p /= x;
//	}
//	for(int i = 1; i <= 1000000; i++){
//		if(jl[i] < n) continue;
//		cout<<i<<" "<<jl[i]<<endl;
//		ans *= cal(i, jl[i] / n);
//	}
	cout<<ans;
	return 0;
}
