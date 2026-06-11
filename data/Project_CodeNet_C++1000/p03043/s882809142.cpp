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
ll const maxn = 5e2+1;

double fastpow(double a, ll b)
{
     double res = 1.0;
     while(b){
          if(b&1) res*=a;
          a*=a;
          b/=2;
     }
     return res;
}
void solve()
{    
     ll n,k; cin >> n >> k;
     double ans = 0;
     for(ll i=1; i<=n; i++){

          long double die = (double)1.0/n;
          ll num = i, cnt = 0;

          while(num<k){
               num*=2;
               cnt++;
          }
          double toss = fastpow(0.5, cnt);
          ans += die*toss;

     }
     cout << fixed << setprecision(9)<< ans << endl;
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