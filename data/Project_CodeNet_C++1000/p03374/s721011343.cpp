#include<string>//...........................
#include<cstdio>//....../%/........./%/......
#include<iostream>//.../%/........./%/.......
#include<algorithm>//./%/........./%/........
#include<cmath>//..../%/........./%/.........
#include<cstring>//./%/_______../%/_______...
#include<queue>//../=========/./=========/...
#include<set>//.....................½ñ¤¬×î¸ß£¡
#define mem(s,t) memset(s,t,sizeof(s))
#define meminf(s) memset(s,0x3f,sizeof(s))
#define MAXINT 0x7fffffff
#define INF 0x3f3f3f3f
typedef long long LL;
using namespace std;
//define begin
const int MAXN=100010;
const int MAXM=200010;


//define end
//function begin

LL x[MAXN],v[MAXN],amax[MAXN],bmax[MAXN],a[MAXN],b[MAXN];

//function end

int main()
{
    int n,i;
    LL maxx,t,m;
    LL c;maxx=0;
    scanf("%d%lld",&n,&c);
    for(i=0;i<n;i++){
        scanf("%lld%lld",&x[i],&v[i]);
    }
    a[0]=v[0]-x[0];amax[0]=a[0];
    for(i=1;i<n;i++)a[i]=a[i-1]+v[i]-(x[i]-x[i-1]),amax[i]=max(amax[i-1],a[i]);
    b[n-1]=v[n-1]-(c-x[n-1]);bmax[n-1]=b[n-1];
    for(i=n-2;i>=0;i--)b[i]=b[i+1]+v[i]-(x[i+1]-x[i]),bmax[i]=max(bmax[i+1],b[i]);

    maxx=max(amax[n-1],bmax[0]);
    if(maxx<0)maxx=0;


    for(i=0;i<n;i++){
        if(i-1<0)m=0;
        else m=amax[i-1];
        t=max(a[i]-x[i]+bmax[i+1],b[i]-(c-x[i])+m);
        maxx=max(maxx,t);
        //if(i==n-1)printf("%lld %lld\n",a[i]-x[i]+bmax[i+1],b[i]-(c-x[i])+m);
    }
    printf("%lld",maxx);


    return 0;
}
















/* ¦Ì'sic forever! */
