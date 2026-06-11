#include<bits/stdc++.h>

#define ll long long
#define mp make_pair
#define rep(i, a, b) for(int i = (a);i <= (b);i++)
#define per(i, a, b) for(int i = (a);i >= (b);i--)
#define lowbit(x) x&-x

using namespace std;

typedef pair<int, int> pii;
typedef double db;
const ll mod = 1e9 + 7;
const int N = 1e6 + 50;
int c[N*10];
int n,a[N],s[N*10];

inline int read(){
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-') f = -1; ch = getchar();}
	while(ch >='0' && ch <='9'){x = (x<<3)+(x<<1)+(ch^48); ch = getchar();}
	return x*f;
}
void add(int x){
    for(int i = x;i <= 2*N;i += lowbit(i)) c[i]++;
}
ll query(int x){
    ll sum = 0;
    for(int i = x;i >0 ;i -= lowbit(i)) sum += c[i];
    return sum;
}
bool check(int x){
    for(int i = 1;i <= 2*N;i++) c[i] = 0;
    s[0] = 0;
    for(int i = 1;i <= n;i++)
        s[i] = s[i-1]+(a[i]>=x?1:-1);
    ll sum = 0;
    for(int i = 0;i <= n;i++){
        sum += query(s[i]+N);
        add(s[i] + N);
    }
    return sum >= 1ll*n*(n+1)/4;
}
int main(){
    n = read();
    int l = 0,r = 0;
    for(int i = 1;i <= n;i++){
        a[i] = read();
        r = max(r, a[i]);
    }
    int ans = 0;
    while(l <= r){
        int mid = (l+r)>>1;
        if(check(mid)) l = mid+1;
        else r = mid-1;
    }
    printf("%d\n", r);
}
