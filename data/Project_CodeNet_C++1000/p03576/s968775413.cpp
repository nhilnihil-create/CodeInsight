#include <bits/stdc++.h>
using namespace std;
struct edge {
    int to;     // 辺の行き先
    int weight; // 辺の重み
    edge(int t, int w) : to(t), weight(w) { }
};
using Graph = vector<vector<int>>;
#define rep(i, n)         for(int i = 0; i < (int)(n); i++)
#define brep(n)           for(int bit=0;bit<(1<<n);bit++)
#define erep(i,container) for (auto i : container)
#define irep(i, n)        for(int i = n-1; i >= (int)0; i--)
#define rrep(i,m,n) for(int i = m; i < (int)(n); i++)
#define reprep(i,j,h,w) rep(i,h)rep(j,w)
#define all(x) (x).begin(),(x).end()
#define aall(x,n) (x).begin(),(x).begin()+(n)
#define VEC(type,name,n) std::vector<type> name(n);rep(i,n)std::cin >> name[i];
#define pb push_back
#define pf push_front
#define lb lower_bound
#define ub upper_bound
#define res resize
#define as assign
#define fi first
#define se second
#define itn int
#define mp make_pair
#define sum accumulate
#define keta fixed<<setprecision
#define vvector(name,typ,m,n,a)vector<vector<typ> > name(m,vector<typ> (n,a))
#define vvvector(name,t,l,m,n,a) vector<vector<vector<t> > > name(l, vector<vector<t> >(m, vector<t>(n,a)));
#define vvvvector(name,t,k,l,m,n,a) vector<vector<vector<vector<t> > > > name(k,vector<vector<vector<t> > >(l, vector<vector<t> >(m, vector<t>(n,a)) ));

typedef long long ll;
const int INF = 2000000000;
const ll INF64 = 9223372036854775806ll;
const int mod = 1000000007ll;
const ll  MOD = 1000000007LL;
int main(){
    int n,k;
    std::cin >> n>>k;
    std::vector<ll> x(n),y(n);
    rep(i,n)std::cin >> x[i]>>y[i];
    if(n==2){
        std::cout << abs(x[1]-x[0])*abs(y[1]-y[0]) << std::endl;
    }else if(n==3){
        ll ans=INF64;
        if(k==2){
            
            rep(i,3)rrep(j,i+1,3){
                ans=min(ans,abs(x[i]-x[j])*abs(y[i]-y[j]));
            }
        }
        if(k==3){
            sort(all(x));
            sort(all(y));
            ans=abs(x[2]-x[0])*abs(y[2]-y[0]);
        }
        std::cout << ans << std::endl;
    }else{
        ll ans=INF64;
        if(k==2){
            rep(i,n)rrep(j,i+1,n){
                ans=min(ans,abs(x[i]-x[j])*abs(y[i]-y[j]));
            }
        }
        if(k==3){
            rep(i,n)rrep(j,i+1,n)rrep(ii,j+1,n){
                int cnt=0;
                ll xa,xz,ya,yz;
                xa=min({x[i],x[j],x[ii]});
                xz=max({x[i],x[j],x[ii]});
                ya=min({y[i],y[j],y[ii]});
                yz=max({y[i],y[j],y[ii]});
                ans=min(ans,abs(xa-xz)*abs(ya-yz));
            }
        }
        else{
            rep(i,n)rrep(j,i+1,n)rrep(ii,j+1,n)rrep(jj,ii+1,n){
                int cnt=0;
                ll xa,xz,ya,yz;
                xa=min({x[i],x[j],x[ii],x[jj]});
                xz=max({x[i],x[j],x[ii],x[jj]});
                ya=min({y[i],y[j],y[ii],y[jj]});
                yz=max({y[i],y[j],y[ii],y[jj]});
                rep(t,n){
                    if(x[t]>=xa&&x[t]<=xz&&y[t]>=ya&&y[t]<=yz)cnt++;
                }
                if(cnt>=k)ans=min(ans,abs(xa-xz)*abs(ya-yz));
            }
        }
        std::cout << ans << std::endl;
    }
}