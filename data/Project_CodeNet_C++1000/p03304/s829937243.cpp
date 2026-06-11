#include <bits/stdc++.h> 

using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;

#define INF LONG_MAX
#define MOD 1000000007
#define rng(a) a.begin(),a.end()
#define rrng(a) a.end(),a.begin()
#define endl "\n"

double mpow(double x,int n){
  using i64=int_fast64_t;
  if(n==0)return 1;
  if(n%2)return x*mpow(x,n-1);
  else {
    i64 half=mpow(x,n/2);
    return half*half;
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  double n,m,d;
  cin>>n>>m>>d;
  if(d==0)cout<<fixed<<setprecision(20)<<(m-1)/n<<endl;
  else cout<<fixed<<setprecision(20)<<(m-1)*(2*(n-d))/(n*n)<<endl;
  return 0;
}
