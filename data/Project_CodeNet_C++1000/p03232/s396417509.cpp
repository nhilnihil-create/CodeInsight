#include<bits/stdc++.h>
using namespace std;

void read(int &x) {
    x=0;int f=1;char ch=getchar();
    for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-f;
    for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';x*=f;
}

void print(int x) {
    if(x<0) putchar('-'),x=-x;
    if(!x) return ;print(x/10),putchar(x%10+48);
}
void write(int x) {if(!x) putchar('0');else print(x);putchar('\n');}

#define lf double
#define ll long long 

#define pii pair<int,int >
#define vec vector<int >

#define pb push_back
#define mp make_pair
#define fr first
#define sc second

#define data asd09123jdf02i3h

#define FOR(i,l,r) for(int i=l,i##_r=r;i<=i##_r;i++)

const int maxn = 1e6+10;
const int inf = 1e9;
const lf eps = 1e-8;
const int mod = 1e9+7;

int n,a[maxn],inv[maxn];

int main() {
    read(n);
    for(int i=1;i<=n;i++) read(a[i]);
    inv[0]=inv[1]=1;
    for(int i=2;i<=n;i++) inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
    for(int i=1;i<=n;i++) inv[i]=(inv[i]+inv[i-1])%mod;
    int ans=0;
    for(int i=1;i<=n;i++) {
        int x=(inv[i]-1+inv[n-i+1]-2)%mod;
        ans=(ans+1ll*x*a[i]%mod)%mod;
    }
    for(int i=1;i<=n;i++) ans=1ll*ans*i%mod;
    write(ans);
    return 0;
}
