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

vector<int> G[100'010];
vector<int> Gf[100'010];
vector<long long> dist(100'010, INF);
bool used[100'010];

int main(){
  
  int k;
  cin>>k;
  REP(i,k){
    G[i].push_back((i+1)%k);
    Gf[i].push_back((10*i)%k);
  }
  
  deque<int> d;
  d.push_back(1);
  dist[1] = 0;
  //used[1] = true;
  while(!d.empty()){
    int now = d.front();
    d.pop_front();
    for(int next_:Gf[now]){
      //if(used[next_])continue;
      if(dist[next_]>dist[now]){
        d.push_front(next_);
        dist[next_] = dist[now];
        //used[next_] = true;
      }
    }
    for(int next_:G[now]){
      //if(used[next_])continue;
      if(dist[next_]>dist[now]+1){
        d.push_back(next_);
        dist[next_] = dist[now]  + 1;
        //used[next_] = true;
      }
    }
  }
  
  long long ans = dist[0] + 1;
  cout<<ans<<endl;
  return 0;
}
