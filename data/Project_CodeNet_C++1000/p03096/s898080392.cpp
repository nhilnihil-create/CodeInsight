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

int n,a[maxn],f[maxn],s[maxn],pre[maxn],t[maxn];

int main() {
    read(n);for(int i=1;i<=n;i++) read(a[i]);
    for(int i=1;i<=n;i++) pre[i]=t[a[i]],t[a[i]]=i;
    f[0]=s[0]=1;
    for(int i=1;i<=n;i++) {
        if(!pre[i]||pre[i]==i-1) {s[i]=s[i-1];continue;}
        f[i]=s[pre[i]],s[i]=(f[i]+s[i-1])%mod;
    }
    // for(int i=1;i<=n;i++) printf("%d %d\n",i,f[i]);
    write(s[n]);
    return 0;
}
