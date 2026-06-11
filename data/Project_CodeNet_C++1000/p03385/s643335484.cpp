#include <bits/stdc++.h>
#define ri register
#define int long long
using namespace std; const int N=200010;
inline int read()
{
    int s=0, w=1; ri char ch=getchar();
    while(ch<'0'||ch>'9') { if(ch=='-') w=-1; ch=getchar(); }
    while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48), ch=getchar();
    return s*w;
}
string s;
signed main()
{
    cin>>s;
    sort(s.begin(),s.end());
    if(s=="abc") puts("Yes");
    else puts("No");
    return 0;
}