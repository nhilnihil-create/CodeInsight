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

int x,y,n,m,k;
char s[maxn],t[maxn];

int main() {
    read(n),read(m),read(k),read(x),read(y);
    scanf("%s%s",s+1,t+1);
    int l=1,r=m;
    for(int i=k;i;i--) {
        if(t[i]=='L') r=min(m,r+1);
        if(t[i]=='R') l=max(1,l-1);
        if(s[i]=='R') r--;
        if(s[i]=='L') l++;
        if(l>r) return puts("NO"),0;
        // l=max(l,1),r=min(r,m);
    // printf("%d %d\n",l,r);
    }
    if(y<l||y>r) return puts("NO"),0;
    // puts("OK");
    l=1,r=n;
    for(int i=k;i;i--) {
        if(t[i]=='U') r=min(n,r+1);
        if(t[i]=='D') l=max(1,l-1);
        if(s[i]=='D') r--;
        if(s[i]=='U') l++;
        if(l>r) return puts("NO"),0;
        // l=max(l,1),r=min(r,n);
    }
    if(x<l||x>r) return puts("NO"),0;
    puts("YES");
    return 0;
}
