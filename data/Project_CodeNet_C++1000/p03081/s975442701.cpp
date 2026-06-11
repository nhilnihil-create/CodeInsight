#include <bits/stdc++.h>
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
  
  int n,q;
  cin>>n>>q;
  string s;
  cin>>s;
  char t[q], d[q];
  REP(i,q){
    cin>>t[i]>>d[i];
  }
  
  int l = 0, r = n+1;//(l,r]:左から落ちない範囲
  while(r-l>1){
    int m = (l+r)/2;
    int now = m;
    REP(i,q){
      if(now == 0 || now == n+1)break;
      if(s[now-1] == t[i]){
        if(d[i] == 'L'){
          now--;
        }else{
          now++;
        }
      }else{
        continue;
      }
    }
    if(now == 0){
      l = m;
    }else{
      r = m;
    }
  }
  int left = r;
  
  l = 0, r = n+1;//[l,r):右から落ちない範囲
  while(r-l>1){
    int m = (l+r)/2;
    int now = m;
    REP(i,q){
      if(now == 0 || now == n+1)break;
      if(s[now-1] == t[i]){
        if(d[i] == 'L'){
          now--;
        }else{
          now++;
        }
      }else{
        continue;
      }
    }
    if(now == n+1){
      r = m;
    }else{
      l = m;
    }
  }
  int right = l;
  
  int ans;
  if(left == n+1){
    ans = 0;
  }else if(right == 0){
    ans = 0;
  }else if(left > right){
    ans = 0;
  }else{
    ans = right - left + 1;
  }
    
  cout<<ans<<endl;
  return 0; 
}
