#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int> >;
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
const ll INF64 = 1000000000000000ll;
const ll MOD = 1000000007LL;
int main(){
    int n,c;
    std::cin >> n>>c;
    vvector(d,ll,c,c,0ll);
    reprep(i,j,c,c)std::cin >> d[i][j];
    vvector(co,ll,3,c,0ll);
 //   std::cout << "nurupo" << std::endl;
    reprep(i,j,n,n){
        int dum;
        std::cin >> dum;
        co[(i+j)%3][dum-1]++;
        
    }
    ll ans=INF64;
    reprep(i,j,c,c)rep(k,c){
        ll dum=0ll;
        if(i==j||i==k||k==j)continue;
        rep(ii,c){
            dum+=co[0][ii]*d[ii][i];
            dum+=co[1][ii]*d[ii][j];
            dum+=co[2][ii]*d[ii][k];
            
        }
       // std::cout <<i<<j<<k<< dum << std::endl;
        ans=min(dum,ans);
    }
    std::cout << ans << std::endl;
    
}
