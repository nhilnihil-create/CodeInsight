#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
#define ld long double
#define mid (l+r)/2
typedef pair<int,int> pii;
const int maxn=(1<<18)+5;
int a[maxn];
int ans[maxn],mx[maxn];
int tot;
void calc(int id,int n)
{
    for(int i=id;i<=n;i=((i+1)|id))
    {
        ans[i]=max(ans[i],mx[i]+a[id]);
        mx[i]=max(mx[i],a[id]);
        ++tot;
    }
}
int main()
{
    #ifdef local
    freopen("in.txt","r",stdin);
    #endif
    IOS;
    int n;
    cin>>n;
    int m=(1<<n)-1;
    for(int i=0;i<=m;i++) cin>>a[i];
    for(int i=0;i<=m;i++) calc(i,m);
    for(int i=1;i<=m;i++)
    {
        ans[i]=max(ans[i],ans[i-1]);
        cout<<ans[i]<<endl;
    }
    //cout<<tot<<endl;
}
