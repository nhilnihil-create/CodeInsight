#include <bits/stdc++.h>
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template<class T> using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;

typedef long long  ll;
typedef unsigned long long  ull;
#define lp(i,n)      for(int i=0;i<n;i++)
#define lpi(i,j,n)   for(int i=j;i<n;i++)
#define lpd(i,j,n)   for(int i=j;i>=n;i--)
#define MP           make_pair
#define clr(v, d)    (memset(v, d, sizeof(v)))
#define all(v)     (v.begin()),(v.end())
#define N 100005
const double pi = acos(-1);

ll n,t,m,k;

ll ans;
ll mod = 1e9 +7;


int main() {
 
ios_base::sync_with_stdio(0);
cin.tie(0);cout.tie(0);
// freopen("e.txt","r",stdin); 
// freopen("e_out.txt","w",stdout); 
cout.precision(7);

cin>>n>>k;
vector<ll>a(n);

lp(i,n)cin>>a[i];
// ll pos = min_element(all(a)) - a.begin();
// ll md1 = pos%(k-1);
// ll md2 = (n-pos-1)%(k-1);
// if(md1>=md2){
//   ans = (pos+k-2)/(k-1);
//   pos += md1;
//   ans += (n-pos-1 +k -2)/(k-1);
// }
// else 
n--;
ans = (n+k-2)/(k-1);
cout<<ans;






  
}
  
 



// bool isPrime(ll h){
//      for(ll i=0;primes[i]*primes[i]<= h;i++)
//      if (h%primes[i]==0)
//      	return 0;
//      return h!=1;
//  }
 bool isPrime(ll g){
   if((g%2==0 && g>2) || g==1)return 0;
   for(ll i=3;i*i<=g;i+=2)if(g%i==0)return 0;
   return 1;   
 
 }