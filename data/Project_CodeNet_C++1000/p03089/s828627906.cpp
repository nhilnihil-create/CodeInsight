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
#define i_7 (long long)(1e9+7)
//#define i_7 998'244'353
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
  int b[n];
  REP(i, n) cin>>b[i];
  vector<int> now;
  REP(i, n) now.push_back(b[i] - 1);
  vector<int> ans;
  bool possible = true;
  REP(i, n){
    int k = -1;
    int m = now.size();
    for(int j = m - 1; j >= 0; j--){
      if(now[j] == j){
        k = j;
        break;
      }
    }
    if(k < 0){
      possible = false;
      break;
    }
    vector<int> temp;
    for(int j = 0; j < m; j++){
      if(j == k) continue;
      temp.push_back(now[j]);
    }
    now = temp;
    ans.push_back(k + 1);
  }
  if(!possible){
    cout << -1 << endl;
    return 0;
  }
  reverse(ALL(ans));
  REP(i, n) cout << ans[i] << endl;
  return 0;
}
