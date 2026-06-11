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

vector<int> G[100'010];
int color[100'010];//0:未踏 1:白 -1:黒

bool dfs(int v, int c){
  bool res = true;
  color[v] = c;
  for(int nv:G[v]){
    if(color[nv] == 0){
      bool temp = dfs(nv, -c);
      if(!temp){
        return false;
      }
      //res = !res || dfs(nv, -c);
    }else{
      if(color[nv] == color[v]){
        return false;
      }else{
        continue;
      }
    }
  }
  return res;
}
  
int main(){
  
  int n,m;
  cin>>n>>m;
  int a[m],b[m];
  REP(i,m){
    cin>>a[i]>>b[i];
    a[i]--;b[i]--;
    G[a[i]].push_back(b[i]);
    G[b[i]].push_back(a[i]);
  }
  bool flag = dfs(0, 1);
  long long w = 0;
  long long ans;
  if(flag){
    REP(i,n){
      if(color[i] == 1){
        w++;
      }
    }
    ans = w*((long long)n-w) - (long long)m;
  }else{
    ans = (long long)n*((long long)n-1)/2 - (long long)m;
  }
  cout<<ans<<endl;   
  return 0; 
}
