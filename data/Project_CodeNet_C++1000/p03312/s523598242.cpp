#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3")
#define REP(i,n) for(int i=0;i<n;i++)
#define REPP(i,n) for(int i=1;i<=n;i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define EPS (1e-9)
#define INF (1e17)
#define PI (acos(-1))
//const double PI = acos(-1);
//const double EPS = 1e-15;
//long long INF=(long long)1E17;
//#define i_7 (long long)(1e9+7)
#define i_7 998'244'353
long mod(long a){
    long long c=a%i_7;
    if(c>=0)return c;
    return c+i_7;
}
long long po(long a, long b){
    if(b==0){
        return 1;
    }
    
    long long z = po(a,b/2);
    z = mod(z*z);
    if(b%2!=0){
        z = mod(a*z);
    }
    return z;
}
 
bool prime_(int n){
  if(n==1){
    return false;
  }else if(n==2){
    return true;
  }else{
    for(int i=2;i<=std::sqrt(n);i++){
      if(n%i==0){
        return false;
      }
    }
    return true;
  }
}
 
long long gcd_(long long a, long long b){
  if(a<b){
    std::swap(a,b);
  }
  if(a%b==0){
    return b;
  }else{
    return gcd_(b,a%b);
  }
}
 
long long lcm_(long long x, long long y){
  return (x/gcd_(x,y))*y;
}
 
//using namespace std;
//using namespace boost::multiprecision;
//using namespace __gnu_pbds;

int main(){
  using namespace std;
  int n;
  cin>>n;
  vector<long long> a(n);
  REP(i, n) cin>>a[i];
  
  long long ans = INF;
  vector<long long> d(n);
  REP(i, n) d[i] = a[i]; REPP(i, n - 1) d[i] += d[i - 1];
  for(int m = 2; m <= n - 2; m++){// [0, m), [m, n) で分ける。
    //[0, l) [l, m) [m, r) [r, n) で分けたい。
    
    int l = upper_bound(d.begin(), d.begin() + m, d[m - 1] / 2) - d.begin();
    if(l == m) l--;
    if(l == 0) l++;
    if(l > 1) if(abs(d[m - 1] - 2 * d[l - 1]) > abs(d[m - 1] - 2 * d[l - 2])) l--;
    if(l + 1 < m) if(abs(d[m - 1] - 2 * d[l - 1]) > abs(d[m - 1] - 2 * d[l])) l++;
    long long P = d[l - 1];
    long long Q = d[m - 1] - d[l - 1];
    
    int r = upper_bound(d.begin() + m, d.end(), (d[n - 1] + d[m - 1]) / 2) - d.begin();
    if(r == n) r--;
    if(r == m) r++;
    if(r > m + 2) if(abs(d[n - 1] - 2 * d[r - 1] + d[m - 1]) > abs(d[n - 1] - 2 * d[r - 2] + d[m - 1])) r--;
    if(r + 1 < n) if(abs(d[n - 1] - 2 * d[r - 1] + d[m - 1]) > abs(d[n - 1] - 2 * d[r] + d[m - 1])) r++;
    long long R = d[r - 1] - d[m - 1];
    long long S = d[n - 1] - d[r - 1];
    
    long long temp = max(max(P, Q), max(R, S)) - min(min(P, Q), min(R, S));
    ans = min(ans, temp);
    
    /*
    cout << "m: " << m << endl;
    cout << "P: " << P << ", Q: " << Q << ", R: " << R << ", S: " << S << endl;
    cout << "temp: " << temp << endl;
    */
  }
  cout << ans << endl;
  return 0;
}
