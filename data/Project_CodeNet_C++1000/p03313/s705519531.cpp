#include <bits/stdc++.h>
#include<ext/pb_ds/hash_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
#define N 500005
using namespace __gnu_pbds;
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
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
int read(){
	int x, f = 1;
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
int a[N];
int f[N];
struct node{
	int a, b;
}d[N];
void work(node &t, int x){
	if(t.a == x || t.b == x) return;
	if(a[t.a] < a[x]) t.b = t.a, t.a = x;
	else if(a[t.b] < a[x]) t.b = x;
}
int main(){
	int i, j, t, n, m;
	n = read();
	for(i = 0; i < (1 << n); i++) a[i] = read(), d[i].a = i;
	for(i = 1; i < (1 << n); i++){
		for(j = 0; j < n; j++){
			if(1 << j & i){
				t = i ^ (1 << j);
				work(d[i], d[t].a);
				work(d[i], d[t].b);
			}
		}
		f[i] = a[d[i].a] + a[d[i].b];
	}
	for(i = 1; i < (1 << n); i++){
		f[i] = max(f[i], f[i - 1]);
		printf("%d\n", f[i]);
	}
	return 0;
}
