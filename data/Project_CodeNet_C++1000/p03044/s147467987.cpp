#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp> 
//using boost::multiprecision::cpp_int;
using namespace std;
#define ll long long int
#define F first
#define S second
//#define endl "\n"
//#define nl cout<<endl;
#define pb push_back
#define ull unsigned long long 
#define f(i,a,b) for(ll i=a;i<b;i++)
#define Knucklehead ios_base::sync_with_stdio(false);cin.tie(NULL);
//#define mod 100000007
#define mat vector<vector<ll>>
mat cn(ll n, ll m){return vector< vector<ll> >(n, vector<ll>(m));}
bool compare(char &s1,char &s2){return s1 > s2;} 
bool sortmahstyle(const pair<ll,ll> &a,  const pair<ll,ll> &b) 
{ 
    if(a.second > b.second )
        return true;
    if( a.second==b.second && a.first > b.second )
       return true;
    return false;
}
bool cmp(int n, pair<int, int> const& p)
{
    return (p.first < n);
}
//me
ll const mod = 1e9+7;//998244353;
ll const inf = 1e18;
ll const maxn = 1e5+1;

vector<pair<ll,ll>> nodes[maxn];
ll dis[maxn];

void solve()
{    
     ll n; cin >> n;
     fill(dis, dis+maxn, inf);
     ll m = n-1;
     while(m--){
          ll u,v,w; cin >> u >> v >> w;
          nodes[u].pb({v,w});
          nodes[v].pb({u,w});
     }

     priority_queue< pair<ll,ll> , vector<pair<ll,ll>> , greater<pair<ll,ll>> > pq;
     pq.push({0,1});
     dis[1]=0;
     while(!pq.empty()){

          ll curNode = pq.top().S;
          ll curWgt = pq.top().F;
          pq.pop();
          if( curWgt > dis[curNode])
               continue;

          for(auto ch : nodes[curNode]){

               if( curWgt + ch.S < dis[ch.F]){
                    dis[ch.F] = curWgt + ch.S;
                    pq.push({dis[ch.F], ch.F});
               }

          }

     }
     ll col[n+1];
     fill(col, col+n+1, 0);
     f(i,1,n+1){
          //cout << dis[i] << "<--" << endl;
          if(dis[i]%2==0)
               col[i]=1;
     }

     f(i,1,n+1)
          cout << col[i] << endl;

}

int main() {
Knucklehead 
//*
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
/**/ 
        
          ll t;
          /**/t=1;
          /*/cin>>t;/**/
          f(testcases,0,t){
               //cout << "Case #" <<testcases+1<<": ";
               solve();
          }
 
 
    return 0;
}