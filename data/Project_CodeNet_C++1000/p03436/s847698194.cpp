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
ll const maxn = 2e5+1;

ll const dx[] = {1,-1,0,0};
ll const dy[] = {0,0,1,-1};
ll vis[51][51];
ll dis[51][51];

bool legal(ll a,ll b, ll x, ll y)
{
     return ( (a>=0&&a<x) && (b>=0&&b<y) );
}
void solve()
{    

     ll h,w; cin >> h >> w;
     string s[h]; f(i,0,h) cin >> s[i];

     ll black = 0;
     f(i,0,h) f(j,0,w) if(s[i][j]=='#') black++;
     if(s[0][0]=='#'){
          cout << -1 ;
          return;
     }
     queue<pair<ll,ll>> q;
     q.push({0,0});
     vis[0][0]=1;

     while(!q.empty()){

          ll curX = q.front().F;
          ll curY = q.front().S;
          q.pop();

          f(i,0,4){
               ll chX = curX+dx[i]; 
               ll chY = curY+dy[i];
               if(legal(chX,chY,h,w) && s[chX][chY]=='.'&&vis[chX][chY]==0 ){
                    vis[chX][chY]=1;
                    dis[chX][chY] = dis[curX][curY]+1;
                    q.push({chX, chY});
               } 
          }
     }

     if(dis[h-1][w-1]==0){
          cout << -1 ;
          return;
     }

     cout << h*w - (black+dis[h-1][w-1]+1);
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