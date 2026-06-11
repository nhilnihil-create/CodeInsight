#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector> 
#include <cstring>
#include <queue>
#include <stack>
#include <ctime>
#include <set>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;


namespace io{
    const int L = (1 << 20) + 1;
    
    char buf[L], *S , *T, c;
     
    char getchar() {
        if(S == T) {
            T = (S = buf) + fread(buf, 1, L, stdin);
            return (S == T ? EOF : *S++);
        }
        return *S++;
    }
    
    int inp() {
        int x = 0, f = 1; char ch;
        for(ch = getchar(); !isdigit(ch); ch = getchar())
            if(ch == '-') f = -1;
        for(; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
        return x * f;
    }
    
    ll inp_ll() {
        ll x = 0; int f = 1; char ch;
        for(ch = getchar(); !isdigit(ch); ch = getchar())
            if(ch == '-') f = -1;
        for(; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
        return x * f;
    }
    
    char B[25], *outs=B+20, *outr=B+20;
    template<class T>
    inline void print(register T a,register char x=0){
        if(x) *--outs = x, x = 0;
        
        if(!a)*--outs = '0';
        else 
            while(a)
                *--outs = (a % 10) + 48, a /= 10;
        
        if(x)
            *--outs = x;
        
        fwrite(outs, outr - outs , 1, stdout);
        outs = outr;
    }
};

using io :: print;
using io :: inp;
using io :: inp_ll;

const int maxN = 100010;
int a[maxN];
int p[maxN];
int tree[2*maxN];          //有负数的情况 
int n;
ll ans;
int lowbit(int x)
{
	return x&(-x);	
} 
void add(int x,int rel)
{
	int i = (x + n+ 1);
	for(;i<=2*n+2;i+=lowbit(i))
	{
		tree[i] += rel;
	}
}
ll sum(int x)
{
	int i = (x + n+ 1);
	ll s = 0;
	for(;i; i -= lowbit(i))
	{
		s += (ll)tree[i];
	}	
	return s;
} 
bool check(int x)
{
	for(int i=1;i<=n;i++)
	{
		if(a[i] >= x)
			p[i] = 1;
		else
			p[i] = -1;
		p[i] += p[i-1];
	}  //计算前缀和 
	for(int i=0;i<=2*n+2;i++)
	{
		tree[i] = 0;
	}
	ll tot = 0;
	add(0,1);
	for(int i=1;i<=n;i++)
	{
		tot += sum(p[i]);
		add(p[i],1);	
	}
	
	if(tot >= ans)
		return true;
	else
		return false;
}
int main()
{
	n = inp();

	ans = 1ll * n*(n+1)/2;
	ans = (ans/2);
	for(int i=1;i<=n;i++)
	{
		a[i] = inp();	
	}
	if(n == 1)
	{
		printf("%d\n",a[1]);
		return 0;
	}
	int L = 1,R = 1e9;
	int cnt = 0;
	while(L<=R)
	{
		int mid = (L+R)/2;
		if(check(mid))
		{
			cnt = mid;
			L = mid + 1;
		}
		else
		{
			R = mid - 1;
		}
	}
	printf("%d\n",cnt);
    return 0;
}