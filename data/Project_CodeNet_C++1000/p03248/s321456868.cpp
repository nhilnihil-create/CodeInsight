#include <bits/stdc++.h>
#include<ext/pb_ds/hash_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
#define N 100005
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
char s[N];
int a[N];
struct node{
	int a, b;
}d[N * 3];
int cnt;
void cr(int a, int b){
	d[++cnt].a = a; d[cnt].b = b;
}
int main(){
	int i, j, n, m, tot = 0, x;
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for(i = 1; i <= n; i++) a[i] = s[i] - '0';
	if(!a[1] || !a[n - 1] || a[n]){
		printf("-1");
		return 0;
	}
	for(i = 2; i <= n - 2; i++){
		if(a[i] != a[n - i]){
			printf("-1");
			return 0;
		}
	}
	x = 1;
	for(i = 2; i <= n; i++){
		cr(i, x);
		if(a[i - 1] == 1) x = i;
	}
	for(i = cnt; i >= 1; i--) printf("%d %d\n", d[i].a, d[i].b);
	return 0;
}