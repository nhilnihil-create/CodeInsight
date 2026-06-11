#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define rc(x) return cout<<x<<endl,0
#define pb push_back
#define in insert
#define er erase
#define fd find
#define fr first
#define sc second
typedef long long ll;
const ll INF=0x3f3f3f3f3f3f3f3f;
const ll llinf=(1LL<<61);
const int inf=(1<<30);
const int nmax=1e5+50;
const int mod=1e9+7;
using namespace std;
int n,m,i,x,y,nxt,st,ed;
int a,b;
int main()
{
    //freopen("dijkstra.in","r",stdin);
    //freopen("dijkstra.out","w",stdout);
    ios_base::sync_with_stdio(false);cin.tie(0);cerr.tie(0);cout.tie(0);
    cin>>a>>b;
    if(a+b==15)cout<<'+'<<endl;
    else if(a*b==15)cout<<'*'<<endl;
    else cout<<'x'<<endl;
    return 0;
}
