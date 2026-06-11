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


void solve()
{    
     
     ll r,D,x; cin >> r >> D >> x;

     ll ans = x;
     f(i,0,10){
          ans = r*ans - D;
          cout << ans << endl;
     }     

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