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

int main()
{
    fastio();
    int n,m,L,R; cin>>n>>m;
    rep(i,1,m){
        cin>>L>>R;
        a[L]++;a[R+1]--;
    }int ans = 0;
    rep(i,1,n){
        a[i] += a[i-1];
        if(a[i]==m) ans++;
    }cout<<ans<<endl;
    return 0;
}
