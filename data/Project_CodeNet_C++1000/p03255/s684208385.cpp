#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cmath>
#include<cctype>
using namespace std;
const long long inf=(1ll<<60);
const double eps=1e-10;
const double pi=acos(-1.0);
//char buf[1<<15],*S=buf,*T=buf;
//char getch(){return S==T&&(T=(S=buf)+fread(buf,1,1<<15,stdin),S==T)?0:*S++;}
inline long long read(){
    long long x=0,f=1;char ch;ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=0;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch&15);ch=getchar();}
    if(f)return x;else return -x;
}
const int N=5e5+10;
long long sum[N],F,ans=inf,n,op,x,ed;
int main()
{
    n=read();x=read();
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+read();
    for(long long j=1;j<=n;j++){
        F=(n+j)*x+5ll*sum[n];ed=(n-j-1)/j+1;
        for(long long v=2;v<=ed;v++){
            F+=2*sum[n-v*j];
            if(F<=0ll){F=inf;break;}
        }
        ans=min(ans,F);
    }
  printf("%lld\n",ans);
    return 0;
}
