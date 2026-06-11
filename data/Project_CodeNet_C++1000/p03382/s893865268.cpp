#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define dbg(x) cout << #x << '=' << x << '\n';
#define ll long long
#define pi pair<int,int>
#define pl pair<ll,ll>
#define pd pair<double,double>
#define ld long double
#define pld pair<ld,ld>
#define lg length()
#define sz size()
#define pb push_back
#define MAXN 100005
#define INF 1000000005
#define LINF 1000000000000000005
#define x1 xdddddddddddddddddd
#define y1 ydddddddddddddddddd

int n,a[100005],x,y,t;

int32_t main(){
    ios_base :: sync_with_stdio(0); cin.tie(); cout.tie();
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        x=max(x,a[i]);
    }
    t=INF;
    for(int i=1;i<=n;i++){
        if(a[i]==x) continue;
        if(abs(x-2*a[i])<t) t=abs(x-2*a[i]),y=a[i];
    }
    cout << x << ' ' << y;
}
