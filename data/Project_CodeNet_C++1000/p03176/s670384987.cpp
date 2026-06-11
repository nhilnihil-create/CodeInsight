#include <bits/stdc++.h>
#define BPhuong "main"
#define maxn 200005
#define maxm
#define fi(i,a,b) for(int i = a; i<= b; i++)
#define fid(i,a,b) for(int i = a; i>= b; i--)
#define se second
#define f first
#define ll long long
#define pii pair<int, int>
#define pb push_back
#define bit(x, i) ((x>>i)&1)
#define oo 1e9
struct data{
    int x, y, z;
};
using namespace std;
int n, h[maxn], a[maxn];
ll l[maxn], f[maxn];
void upp(int x, ll j)
{
    while(x<=maxn)
    {
        l[x] = max(l[x], j);
        x+=(x&-x);
    }
}
ll get(int x)
{
    ll ans = 0;
    while(x>=1)
    {
        ans = max(ans, l[x]);
        x -= (x&-x);
    }
    return ans;
}
void nhap(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
   // freopen(BPhuong".inp","r",stdin);
    //freopen(BPhuong".out","w",stdout);
    cin >> n;
    fi(i, 1, n) cin >> h[i];
    fi(i, 1, n) cin >> a[i];
}

void xuli(){
    ll res = 0;
    fi(i, 1, n)
    {
       f[i] = max(f[i], get(h[i]-1) + a[i]);
       upp(h[i], f[i]);
       res = max(res, f[i]);
    }
    cout << res;
}

int main(){
    nhap();
    xuli();
}
