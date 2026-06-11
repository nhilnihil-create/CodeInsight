#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,q;
#define Maxn 200010
int mins[Maxn];

inline void rd(int &x){
    x=0;char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
}

int main(){
    memset(mins,127,sizeof(mins));
    rd(n);rd(m);rd(q);
    int x,y;
    for(register int i=1;i<=q;++i){
        rd(x);rd(y);
        x--;y--;
        mins[x]=min(mins[x],y);
    }
    int right=0;
    for(register int i=1;i<n;++i)
        if(right>=mins[i]){
            printf("%d\n",i);
            return 0;
        }else if(right+1<mins[i])right++;
    printf("%d\n",n);
    return 0;
}