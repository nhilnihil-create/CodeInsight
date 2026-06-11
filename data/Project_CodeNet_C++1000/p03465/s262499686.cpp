//by aman kumar 
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype> 
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define int          long long int
#define pb           push_back
#define pob          pop_back
#define pr           pair<int,int>
#define all(a)       a.begin(),a.end()
#define allr(a)      a.rbegin(),a.rend()
#define F            first
#define S            second
#define mst          multiset<int,int>
#define rep(i,a,b)   for(int i=a;i<b;i++)
#define pii          pair<int,int>
#define endl         "\n" 
#define vi          vector<int>
#define elasped_time 1.0 * clock() / CLOCKS_PER_SEC 
void optimise(){ios_base::sync_with_stdio(false);cin.tie(NULL);}
int mod = 1e9+7;
void normalize(int &a){a = (a + mod) % mod;}
int modmul(int a,int b){a=a%mod;b=b%mod;normalize(a);normalize(b);return (a*b)%mod;}
int modadd(int a,int b){a=a%mod;b=b%mod;normalize(a);normalize(b);return (a+b)%mod;}
int modsub(int a,int b){a=a%mod;b=b%mod;normalize(a);normalize(b);return (a-b+mod)%mod;}
int me(int x,int n){x%=mod;if(n==0)return 1;int u=me(x,n/2)%mod;u=(u*u)%mod;if(n%2)u=(u*x)%mod;return u;}
int me1(int x,int n ){if(n == 0)return 1;int u=me1(x,n/2);u=u*u;if(n%2)u=u*x;return u;}
inline  int modInv(int a) { return me(a, mod-2); }
inline  int modDiv(int a,int b) { return modmul(a, modInv(b)); }
float power(float x, int y)  
{  
    float temp;  
    if(y == 0)  
        return 1;  
    temp = power(x, y / 2);  
    if (y % 2 == 0)  
        return temp * temp;  
    else
    {  
        if(y > 0)  
            return x * temp * temp;  
        else
            return (temp * temp) / x;  
    }  
}  
int __gcd(int a,int b){if(b == 0)return a;else return __gcd(b,a%b);}
pii operator+(pii a,pii b){return {a.F+b.F,a.S+b.S};}
pii operator-(pii a,pii b) {return {a.F-b.F,a.S-b.S};}
pii operator*(pii a,pii b){return {a.F*b.F,a.S*b.S};}
template <typename T>ostream& operator<<(ostream& os, const set<T>& v){for (auto it : v) os << it<<" "; return os;}
template <typename T>ostream& operator<<(ostream& os, const vector<T>& v){for (int i = 0; i < v.size(); ++i)os << v[i]<<" ";return os;}
const int N = 2e5+1;
int a[N]; 
int vis[N];
int cyc,nodes;
void dfs(int v)
{
  vis[v] = 1;
  nodes++;
  if(vis[a[v]] == 0)
  {
    dfs(a[v]);
  }
  else if(vis[a[v]] == vis[v])
  {
     int y = a[v];
     cyc = 1;
     while(y!=v)
     {
       cyc++;
       y = a[y];
     }
     nodes = nodes-cyc;
     vis[v] = 2;
     return;
  }
  else if(vis[a[v]] == 2)
  {
    vis[v] = 2;
    return;
  }

  vis[v] = 2;



}



void solve()
{

  bitset<2000009>dp;
  int n;
  cin>>n;
  int a[n];
  int sum = 0;
  for(int i=0;i<n;i++)
    {
      cin>>a[i];
      sum+=a[i];

    }

    dp[0] = 1;

    for(int i=0;i<n;i++)
      dp|=(dp<<a[i]);

    for(int i=sum/2;i>=0;i--)
    {
      if(dp[i])
        {cout<<sum-i<<" ";return;}

    }
    
  

}




signed main()
{     
     optimise();
     #ifndef ONLINE_JUDGE
    freopen("input.txt",  "r",   stdin); 
    freopen("output.txt", "w",   stdout);
    freopen("error.txt",  "w",   stderr);
    #endif
    int t ;
    t = 1;
   
    
    cout << fixed << setprecision(5);

   while(t--)
 
    {
       solve();
       cout<<endl;
     
    
      

     
      
       
    }
    cerr<<endl<<"Time Elasped : "<<elasped_time<<endl;
   
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 