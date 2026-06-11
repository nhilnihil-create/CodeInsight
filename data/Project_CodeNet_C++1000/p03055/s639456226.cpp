#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
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
using namespace std;
//using namespace boost::multiprecision;

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

vector<int> G[200'010];
int dist[200'010];
void dfs(int v, int p){
  for(int nv:G[v]){
    if(nv == p){
      continue;
    }
    dist[nv] = dist[v] + 1;
    dfs(nv, v);
  }
  return;
}

int main(){
  
  int n;
  cin>>n;
  int a[n-1],b[n-1];
  REP(i,n-1){
    cin>>a[i]>>b[i];
    a[i]--;b[i]--;
    G[a[i]].push_back(b[i]);
    G[b[i]].push_back(a[i]);
  }
  dist[0] = 0;
  dfs(0, -1);
  int c;
  int temp = 0;
  REP(i,n){
    if(temp < dist[i]){
      c = i;
      temp = dist[i];
    }
  }
  dist[c] = 0;
  dfs(c, -1);
  int d = 0;//直径
  REP(i,n){
    d = max(d, dist[i]);
  }
  if(d%3 == 1){
    cout<<"Second"<<endl;
  }else{
    cout<<"First"<<endl;
  }
  return 0; 
}
