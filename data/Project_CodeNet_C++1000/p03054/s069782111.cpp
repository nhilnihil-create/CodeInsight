/*Program from Luvwgyx*/
#include<map>
#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
const int maxn=2e5+10;
int n,m,len,x,y;char s[maxn],t[maxn];
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void print(int x){
    if(x<0)putchar('-'),x=-x;
    if(x>9)print(x/10);
    putchar(x%10+'0');
}
void write(int x){print(x);puts("");}
signed main(){
    n=read();m=read();len=read();x=read(),y=read();
    scanf("%s%s",s+1,t+1);int l=1,r=n;
    for(int i=len;i>=1;i--){
        if(t[i]=='U')r=min(n,r+1);
        if(t[i]=='D')l=max(1ll,l-1);
        if(s[i]=='U')l++;
        if(s[i]=='D')r--;
        if(l>r){puts("NO");return 0;}
    }if(x<l||r<x){puts("NO");return 0;}
    l=1;r=m;
    for(int i=len;i>=1;i--){
        if(t[i]=='L')r=min(m,r+1);
        if(t[i]=='R')l=max(1ll,l-1);
        if(s[i]=='L')l++;
        if(s[i]=='R')r--;
        if(l>r){puts("NO");return 0;}
    }if(y<l||r<y){puts("NO");return 0;}
    puts("YES");
    return 0;
}
