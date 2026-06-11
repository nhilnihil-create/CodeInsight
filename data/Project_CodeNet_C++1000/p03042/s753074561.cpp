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

bool month(ll n)
{
     return ( n>=1&&n<=12);
}
bool year(ll n){
     return (n>=0&&n<=99);
}
void solve()
{    
     ll n; cin >> n;

     ll last = n%10;
     n/=10;
     last += 10*(n%10);
     n/=10;
     bool yymm=0, mmyy=0;
     if( year(n) && month(last) )
          yymm=1;
     if( year(last) && month(n))
          mmyy=1;

     if(mmyy && yymm)
          cout << "AMBIGUOUS";
     else if (mmyy)
          cout << "MMYY";
     else if (yymm)
          cout << "YYMM";
     else 
          cout << "NA";
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