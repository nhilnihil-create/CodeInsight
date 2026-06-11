#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;
const ll INF = 1e18;
struct Point {
    ll x,y;
}a[N];
ll d[50];
ll dir[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
string s="LRUD";
ll n,cnt=0;
ll dis(ll x1, ll y1, ll x2, ll y2) {
    return abs(x1-x2)+abs(y1-y2);
}
void solve(ll x, ll y) {
    Point now={0,0};
    for (int i=1; i<=cnt; i++) {
        ll mi=INF;
        ll pos=0;
        for (int j=0; j<4; j++) {
            ll tx=now.x+dir[j][0]*d[i],ty=now.y+dir[j][1]*d[i];
            ll t=dis(tx,ty,x,y);
            if (mi>t) mi=t,pos=j;
        }
        now.x+=d[i]*dir[pos][0],now.y+=d[i]*dir[pos][1];
        putchar(s[pos]);
    }
    puts("");
}
int main() {
    cin>>n;
    for (int i=1; i<=n; i++) {
        cin>>a[i].x>>a[i].y;
        if((abs(a[i].x+a[i].y)&1)!=(abs(a[1].x+a[1].y)&1)) return 0*puts("-1");
    }
    for (ll i=30; i>=0; i--) d[++cnt]=1<<i;
    if ((a[1].x+a[1].y)%2==0) d[++cnt]=1;
    cout<<cnt<<endl;
    for (int i=1; i<cnt; i++) cout<<d[i]<<" ";
    cout<<d[cnt]<<endl;
    for (int i=1; i<=n; i++) {
        solve(a[i].x,a[i].y);
    }
    return 0;
}