#include <bits/stdc++.h>
#include<ext/pb_ds/hash_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
#define N 100005
using namespace __gnu_pbds;
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
const int mod = 1e9 + 7;
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
LL z = 1;
LL read(){
	LL x, f = 1;
	char ch;
	while(ch = getchar(), ch < '0' || ch > '9') if(ch == '-') f = -1;
	x = ch - '0';
	while(ch = getchar(), ch >= '0' && ch <= '9') x = x * 10 + ch - 48;
	return x * f;
}
int ksm(int a, int b, int p){
	int s = 1;
	while(b){
		if(b & 1) s = z * s * a % p;
		a = z * a * a % p;
		b >>= 1;
	}
	return s;
}
int a[N], s[N], v[250005], n;
void add(int i){
	for(; i < 200009; i += i&-i) v[i]++;
}
LL sum(int i){
	LL s = 0;
	for(; i > 0; i -= i&-i) s += v[i];
	return s;
}
int ok(int x){
	int i;
	memset(v, 0, sizeof(v));
	LL ans = 0;
	for(i = 1; i <= n; i++){
		if(a[i] <= x) s[i] = s[i - 1] + 1;
		else s[i] = s[i - 1] - 1;
	}
	for(i = 0; i <= n; i++){
		ans += sum(s[i] + N - 1);
		add(s[i] + N);
	}
	return ans >= z * n * (n + 1) / 4 + 1;
}
int main(){
	int i, j, m, l = 0, r = 0, mid;
	n = read();
	for(i = 1; i <= n; i++) a[i] = read();
	r = 1e9;
	while(l < r){
		mid = l + r >> 1;
		if(ok(mid)) r = mid;
		else l = mid + 1;
	}
	printf("%d", l);
	return 0;
}
