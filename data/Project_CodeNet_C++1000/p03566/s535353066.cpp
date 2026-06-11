#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#define REP(i,n) for(int i=0;i<n;i++)
#define REPP(i,n) for(int i=1;i<=n;i++)
#define ALL(obj) (obj).begin(), (obj).end()
const double PI = acos(-1);
const double EPS = 1e-15;
long long INF=(long long)1E17;
#define i_7 (long long)(1E9+7)
long mod(long a){
    long long c=a%i_7;
    if(c>=0)return c;
    return c+i_7;
}
using namespace std;
bool prime_(int n){
  if(n==1){
    return false;
  }else if(n==2){
    return true;
  }else{
    for(int i=2;i<=sqrt(n);i++){
      if(n%i==0){
        return false;
      }
    }
    return true;
  }
}

long long gcd_(long long a, long long b){
  if(a<b){
    swap(a,b);
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

int main(){
  
  int n;
  cin>>n;
  double t[n];
  double T = 0.0;
  REP(i,n){
    cin>>t[i];
    T += t[i];
  }
  double v[n+2];
  v[0] = 0;
  v[n+1] = 0;
  REPP(i,n){
    cin>>v[i];
  }
  
  double l[n+2];
  double r[n+2];
  REPP(i,n){
    if(i==1){
      l[i] = 0;
      r[i] = t[i-1];
    }else{
      l[i] = r[i-1];
      r[i] = l[i] + t[i-1];
    }
  }
  l[0] = r[0] = 0.0;
  l[n+1] = r[n+1] = T;
  
  double real_v[2*(int)T+1];
  double temp;
  REP(j,2*(int)T+1){
    REP(i,n+2){
      if(i==0){
        temp = (double)j/2.0;
      }else if(i==n+1){
        temp = min(temp,T-(double)j/2.0);
      }else{
        if((double)j/2.0 < l[i]){
          temp = min(temp, v[i]+l[i]-(double)j/2.0);
        }else if((double)j/2.0 > r[i]){
          temp = min(temp, v[i]+(double)j/2.0-r[i]);
        }else{
          temp = min(temp, v[i]);
        }
      }
    }
    real_v[j] = temp;
  }
  
  double ans = 0.0;
  REP(j,2*(int)T){
    ans += 0.25*(real_v[j]+real_v[j+1]);
  }
  cout << fixed << setprecision(4) << ans << endl;
  return 0;
}
