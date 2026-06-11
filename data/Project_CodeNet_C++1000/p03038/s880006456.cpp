#include<bits/stdc++.h>
#define ll long long
#define pii_ pair<int,int>
#define mp_ make_pair
#define pb push_back
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define show1(a) cout<<#a<<" = "<<a<<endl
#define show2(a,b) cout<<#a<<" = "<<a<<"; "<<#b<<" = "<<b<<endl
using namespace std;
const ll INF = 1LL<<60;
const int inf = 1<<30;
const int maxn = 2e5+5;
inline void fastio() {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}

int a[maxn];
pii_ op[maxn];
int main()
{
    fastio();
    int n,m;cin>>n>>m;
    rep(i,1,n) cin>>a[i];
    sort(a+1,a+n+1);
    rep(i,1,m){
        cin>>op[i].se>>op[i].fi;
    }
    sort(op+1,op+m+1);
    int pos = 1;ll ans = 0;
    int flag = 0;
    per(i,m,1){
        int k = op[i].fi,s = op[i].se;
        rep(j,0,s-1){
            if(pos+j > n || a[pos+j]>=k) {flag = 1;break;}
            a[pos+j] = k;
        }
        pos += s;
        if(flag) break;
    }
    rep(i,1,n) ans += a[i];
    cout<<ans<<endl;
    return 0;
}
