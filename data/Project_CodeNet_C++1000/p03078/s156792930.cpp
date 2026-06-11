#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long LL;
typedef long double ld;
typedef vector<ll>VI;
typedef pair<ll,ll>P;
#define VV(T) vector<vector<T>>
#define sz(x) int(x.size())
#define PI 3.1415926535897932384626433832795
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
#define ALL(a)  (a).begin(),(a).end()
#define rALL(a) (a).rbegin(),(a).rend()
#define c_max(a, b) (((ll)a)>((ll)b)?(a):(b))
#define c_min(a,b) (((ll)a)<((ll)b)?(a):(b))
#define chmax(x,a) x=max(x,a)
#define chmin(x,a) x=min(x,a)
#define vmax(v) *max_element(ALL(v))
#define vmin(v) *min_element(ALL(v))
#define $(x) {cout<<#x<<" = " <<(x)<<endl;}
#define fi first
#define se second
#define MAX 100100//5
#define MAX2 200100
#define MAX6 1001001//6
#define MAX7 10010010//7
#define SENTINEL 2000000000//9
const int MOD = 1000000007;
#define INF 1<<30
#define INFTY 1LL<<61
#define MAX_INT INT_MAX
#define Endl '\n'
#define CLR(mat) memset(mat, 0, sizeof(mat))
inline ll GCD(ll a,ll b){return b?GCD(b,a%b):a;}
inline ll lcm(ll a,ll b){return a*b/GCD(a,b);}
template<class T> bool contain(const std::string& s, const T& v) {
   return s.find(v) != std::string::npos;
}
using Edge=pair<int,ll>;
using Graph=vector<vector<ll> >;//ll or Edge
//const int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
// sort_reverse -> greater<long long>()
// vector型から重複を削除 list.erase(unique(ALL(list)),list.end());
// g++ -o a a.cpp -Wall -lm -std=c++17
//push_back -> emplace_back

int main(){
   int x,y,z,k;
   cin>>x>>y>>z>>k;
   VI A(x),B(y),C(z);
   rep(i,x)cin>>A[i];
   rep(i,y)cin>>B[i];
   rep(i,z)cin>>C[i];
   sort(rALL(C));
   VI AB;
   rep(i,x)rep(j,y){
      AB.push_back(A[i]+B[j]);
   }
   sort(rALL(AB));
   AB.resize(k);
   VI ans;
   rep(i,sz(AB))rep(j,sz(C)){
      ans.emplace_back(AB[i]+C[j]);
   }
   sort(rALL(ans));
   rep(i,k)cout<<ans[i]<<endl;
}