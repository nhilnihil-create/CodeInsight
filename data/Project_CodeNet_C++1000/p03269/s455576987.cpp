#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define int long long
int hmt() {int x=0;int c=getchar(),n=0;for(;!isdigit(c);c=getchar()) n=(c=='-');for(;isdigit(c);c=getchar()) x=x*10+c-'0';if(n) x=-x;return x;}
#define in hmt()
#define ins ({string x;char c=getchar();for(;c==' '||c=='\n';c=getchar());for(;c!=' '&&c!='\n';c=getchar()) x+=c;x;})
#define forinc(i,a,b) for(int i=a,_b=b;i<=_b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
#define forb(i,BS) for(int i=BS._Find_first();i< BS.size();i = BS._Find_next(i))
#define forv(a,b) for(auto &a:b)
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define all(a) a.begin(),a.end()
#define reset(f,x) memset(f,x,sizeof(f))
#define bit(x,i) ((x>>(i-1))&1)
#define onbit(x,i) (x|(1<<(i-1)))
#define offbit(x,i) (x&~(1<<(i-1)))
int n;
struct oo {int a,b,c;};
vector<oo> ans;
main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n;
    int nd=1,o=1;
    while(o*2<=n)
    {
        ans.pb({nd,nd+1,0});
        ans.pb({nd,nd+1,o});
        nd++;
        o*=2;
    }
    while(o<n)
    {
        int res=1,tmp=1;
        while(tmp<=n-o) tmp*=2,res++;
        tmp/=2;res--;
        ans.pb({res,nd,o});
        o+=tmp;
    }
    cout<<nd<<" "<<ans.size()<<" "<<"\n";
    forv(x,ans) cout<<x.a<<" "<<x.b<<" "<<x.c<<"\n";
}
