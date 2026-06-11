#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    ll k,n;cin>>n>>k;
    vector<ll> x(n),y(n);
    rep(i,n) cin>>x[i]>>y[i];
    vector<ll> nx=x,ny=y;
    sort(nx.begin(),nx.end());
    sort(ny.begin(),ny.end());
    ll res=5e18;
    rep(xl,n)rep(xr,n)rep(yl,n)rep(yr,n){
        ll lx=nx[xl],ly=ny[yl],rx=nx[xr],ry=ny[yr];
        ll bufm=abs(rx-lx)*abs(ry-ly);
        ll buf=0;
        rep(i,n){
            ll bufx=x[i],bufy=y[i];
            if(lx<=bufx&&bufx<=rx&&ly<=bufy&&bufy<=ry)buf++;
        }
        //cout<<(rx-lx)<<" "<<(ry-ly)<<" "<<bufm<<endl;
        if(buf>=k)chmin(res,bufm);
    }
    cout<<res<<endl;
}
