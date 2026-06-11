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
signed main()
{
    string s;
    cin>>s;
    for(ri int i=0;i<(1<<3);i++)
    {
        int qwq=0;
        qwq=s[0]-'0';
        for(ri int j=0;j<3;j++)
        {
            if((i>>j)&1ll) qwq+=s[j+1]-'0';
            else qwq-=s[j+1]-'0';
        }
        if(qwq==7)
        {
            cout<<s[0];
            for(ri int j=0;j<3;j++)
            {
                if((i>>j)&1ll) cout<<'+';
                else cout<<'-';
                cout<<s[j+1];
            }
            puts("=7");
            return 0;
        }
    }
    return 0;
}