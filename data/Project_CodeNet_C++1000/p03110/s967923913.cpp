#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int,int>;
using Pl = pair<ll,ll>;
#define REP(i,n) for(ll i = 0;i < (ll)n;i++)
#define REPD(i,n) for(ll i = (ll)n - 1;i >= 0;i--)
#define ALL(x) (x).begin(),(x).end()
#define FILLl(n,first_dimension_size,value) fill((ll*)n,(ll*)(n+first_dimension_size),value)
#define FILL(n,first_dimension_size,value) fill((int*)n,(int*)(n+first_dimension_size),value)
#define INF (1 << 30)
#define MOD 1000000007
//int dy[4] = {-1,0,0,1};
//int dx[4] = {0,1,-1,0};


int main(){
  
  int n;
  cin >> n;
  double res = 0;
  REP(i,n){
    double x;
    string s;
    cin >> x >> s;
    if(s == "JPY"){
      res += x;
    }else{
      res += x*380000;
    }
  }
  cout << fixed << setprecision(15);
  cout << res << endl;




  return 0;
}