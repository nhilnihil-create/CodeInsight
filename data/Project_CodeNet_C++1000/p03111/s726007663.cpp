#include<map>
#include<set>
#include<cmath>
#include<stack>
#include<queue>
#include<cstdio>
#include<string>
#include<vector>
#include<cstring>
#include<iomanip>
#include<sstream>
#include<iostream>
#include<algorithm>
#define INF 0x3f3f3f3f
#define ls l,m,rt<<1
#define rs m+1,r,rt<<1|1
//#define ll __int64
//#define int ll
typedef  long long ll;
typedef unsigned long long ull;
const int MAXN=1e5+10;
const int MOD=1e9+7;
const double eps=1e-6;
const double finf=1e10;
using namespace std;
template<class T>inline void read(T &res)
{
    char c;T flag=1;
    while((c=getchar())<'0'||c>'9')if(c=='-')flag=-1;res=c-'0';
    while((c=getchar())>='0'&&c<='9')res=res*10+c-'0';res*=flag;
}
//-------------------------------------------//
int l[10],vis[10];
int main()
{
    int n,a,b,c,use,ans=INF;
    cin>>n>>a>>b>>c;
    for(int i=0;i<n;++i)scanf("%d",&l[i]);
    for(int i=1;i<(1<<n);++i)
    {
        int cnt=0,sum=0,c1=0;
        for(int x=0;x<n;++x)
            if((i>>x)&1)cnt++,sum+=l[x];
        c1=(cnt-1)*10+abs(sum-a);
        for(int j=0;j<(1<<n);++j)
        {
            if(i&j||j==0)continue;
            int cnt=0,sum=0,c2=0;
            for(int x=0;x<n;++x)
                if((j>>x)&1)cnt++,sum+=l[x];
            c2=(cnt-1)*10+abs(sum-b);
            for(int k=0;k<(1<<n);++k)
            {
                if(i&k||j&k||k==0)continue;
                use|=k;
                int cnt=0,sum=0,c3=0;
                for(int x=0;x<n;++x)
                    if((k>>x)&1)cnt++,sum+=l[x];
                c3=(cnt-1)*10+abs(sum-c);
                ans=min(ans,c1+c2+c3);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
