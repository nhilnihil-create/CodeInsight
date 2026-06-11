#include<bits/stdc++.h>
#define inf 0x7fffffff
#define RG register
#define maxn 500005
#define maxm 205
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
inline ll read(){
    ll x = 0, f = 1;
    char ch = getchar();
    while(ch > '9' || ch < '0') {if(ch == '-') f = -1;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x *10 + ch -'0';ch = getchar();}
    return x * f;
}

int n, m, sum;
bitset<4000005> f;
int main(){
	int i, j, x;
	n = read();
	f[0] = 1;
	for(i = 1;i <= n;i++) {
		x = read();
		f |= f << x;
		sum += x;
	}
	for(i = (sum + 1)  / 2;i <= sum;i++) if(f[i]) return printf("%d\n",i),0;
	return 0;
}
