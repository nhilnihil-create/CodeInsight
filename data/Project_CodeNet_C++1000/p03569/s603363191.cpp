#include <bits/stdc++.h>
using namespace std;
struct Edge {
    int to;     // 辺の行き先
    int weight; // 辺の重み
    Edge(int t, int w) : to(t), weight(w) { }
};
using Graph = vector<vector<Edge>>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define reprep(i,j,h,w) rep(i,h)rep(j,w)
#define rrep(i,m, n) for(int i = m; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define aall(x,n) (x).begin(),(x).begin()+(n)
#define VEC(type,name,n) std::vector<type> name(n);rep(i,n)std::cin >> name[i];
#define pb push_back
#define pf push_front
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define sum accumulate
#define keta fixed<<setprecision
#define vvector(name,typ,m,n,a)vector<vector<typ> > name(m,vector<typ> (n,a))
#define vvvector(name,t,l,m,n,a) vector<vector<vector<t> > > name(l, vector<vector<t> >(m, vector<int>(n,a)));
typedef long long ll;
const int INF = 2000000000;
const long INF64 = 1000000000000000ll;
const ll MOD = 1000000007LL;
typedef unsigned int uint;
int main(){
    string s,dum;
    std::cin >> s;
    rep(i,s.size()){
      if(s[i]!='x')dum.pb(s[i]);
    }
    bool han=0;
    rep(i,dum.size()/2)if(dum[i]!=dum[dum.size()-1-i])han=1;
    if(han){
      std::cout << -1 << std::endl;
      exit(0);
    }
    int ans=0,c=0;
    std::vector<int> a;
    rep(i,s.size()){
      if(s[i]=='x')c++;
      else{
        a.pb(c);
        c=0;
      }
    }
    a.pb(c);
    rep(i,a.size()/2){
      ans+=abs(a[i]-a[a.size()-i-1]);
    }
    std::cout << ans << std::endl;
}