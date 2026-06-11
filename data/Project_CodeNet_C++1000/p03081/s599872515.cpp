#include<cstdio>
#include<iostream>
int n,q;
const int N=2e5+5;
char s[N],t[N],d[N];
bool check(int x,int p=0) {
    for(int i=1;i<=q&&x>0&&x<=n;i++) {
        if(t[i]==s[x]) d[i]=='L'?x--:x++;
    }
    return x==p;
}
int main() {
    scanf("%d%d",&n,&q);
    scanf("%s",s+1);
    for(int i=1;i<=q;i++) {
        getchar();
        scanf("%c %c",t+i,d+i);
    }
    int low,upp,l=0,r=n+1,mid;
    while(r-l>1) {
        mid=(l+r)>>1;
        if(check(mid)) l=mid;
        else r=mid;
    }
    low=l;l=1,r=n+1;
    while(l<r) {
        mid=(l+r)>>1;
        if(check(mid,n+1)) r=mid;
        else l=mid+1;
    }upp=r;
    printf("%d\n",upp-low-1);
    return 0;
}
