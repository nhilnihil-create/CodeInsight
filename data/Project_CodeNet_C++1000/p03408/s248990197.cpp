#include <bits/stdc++.h>
#define ri register
#define int long long
using namespace std;
inline int read()
{
    int s=0, w=1; ri char ch=getchar();
    while(ch<'0'||ch>'9') { if(ch=='-') w=-1; ch=getchar(); }
    while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48), ch=getchar();
    return s*w;
}
int n,m;
string s[210],t[210];
map<string,int> Q;
int res;
signed main()
{
    cin>>n;
    for(ri int i=1;i<=n;i++) cin>>s[i], Q[s[i]]++;
    m=read();
    for(ri int i=1;i<=m;i++) cin>>t[i], Q[t[i]]--;
    for(ri int i=1;i<=n;i++) res=max(res,Q[s[i]]);
    printf("%lld\n",res);
    return 0;
}