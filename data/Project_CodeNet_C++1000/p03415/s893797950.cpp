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
signed main()
{
    string s,a,b;
    cin>>s>>a>>b;
    cout<<s[0]<<a[1]<<b[2]<<endl;
    return 0;
}