#include<bits/stdc++.h>
using namespace std;
#define fo(i,a,b) for(register int (i)=(a);(i)<=(b);++(i))
#define of(i,a,b) for(register int (i)=(a);(i)>=(b);--(i))
#define rd read()
#define maxn 500001
#define ll long long
#define fre(a) freopen("a.in","r",stdin);freopen("a.out","w",stdout);
const int p=998244353;
int read() {int x=0,f=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}while(isdigit(ch))x=x*10+ch-'0',ch=getchar();return x*f;}
void print(int x) { if(x<0){putchar('-');x=-x;}if(x>9)print(x/10);putchar(x%10+'0');}
int qp(int a, int  b) {int ans = 1;for(; b; b >>= 1, a *= a, a %= p) if(b & 1) ans *= a, ans %= p;return ans % p;}
int main() {
    int a=rd,b=rd,ok=0;
    if(a<=8&&b<=8)ok=1;
    puts(ok?"Yay!":":(");
    return 0;
}