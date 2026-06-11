#include <bits/stdc++.h>
#define ri register
#define int long long
#define E (n+1)
using namespace std; const int N=200010;
inline int read()
{
    int s=0, w=1; ri char ch=getchar();
    while(ch<'0'||ch>'9') { if(ch=='-') w=-1; ch=getchar(); }
    while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48), ch=getchar();
    return s*w;
}
int book[N],res;
signed main()
{
    int n;
    cin>>n;
    for(ri int i=0;i<n;i++)
    {
        char c;
        cin>>c;
        if(!book[c]) book[c]=1, res++;
    }
    (res==3)?puts("Three"):puts("Four");
    return 0;
}