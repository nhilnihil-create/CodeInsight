#pragma GCC optimize(2)
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<queue>
#define PI atan(1.0)*4
#define E 2.718281828
#define rp(i,s,t) for (register int i = (s); i <= (t); i++)
#define RP(i,t,s) for (register int i = (t); i >= (s); i--)
#define ll long long
#define ull unsigned long long
#define mst(a,b) memset(a,b,sizeof(a))
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define debug printf("ac\n");
using namespace std;
inline int read()
{
    int a=0,b=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-')
            b=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        a=(a<<3)+(a<<1)+c-'0';
        c=getchar();
    }
    return a*b;
}
const int INF = 0x3f3f3f3f;
const int N = 2e5+7;
int a[N];
int main(){
    int n=read();
    rp(i,1,n) a[i]=read();
    ll ans=0;
    for(int l=1,r=0,now=0;l<=n;){
        while(r<=n&&(now^a[r])==now+a[r]) now+=a[r++];
        ans+=r-l;
        now^=a[l++];
    }
    cout<<ans<<endl;
    return 0;
}
/*
1 1
1 2
2 2
2 3
2 4
3 3
3 4
4 4
4 5
4 6
4 7
5 5
5 6
5 7
6 6
6 7
6 8
7 7
7 8
8 8
9 9
10 10
10 11
10 12
11 11
11 12
12 12
13 13
14 14
14 15
14 16
15 15
15 16
16 16
17 17
18 18
19 19
37
*/