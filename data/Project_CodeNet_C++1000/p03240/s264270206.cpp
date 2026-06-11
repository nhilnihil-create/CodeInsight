#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
using Pl = pair<ll,ll>;
#define REP(i,n) for(ll i = 0;i < (ll)n;i++)
#define REPD(i,n) for(ll i = (ll)n - 1;i >= 0;i--)
#define ALL(x) (x).begin(),(x).end()
#define FILLl(n,first_dimension_size,value) fill((ll*)n,(ll*)(n+first_dimension_size),value)
#define FILL(n,first_dimension_size,value) fill((int*)n,(int*)(n+first_dimension_size),value)
#define INF (1ll << 62)
#define MOD 1000000007
//int dy[4] = {-1,0,0,1};
//int dx[4] = {0,1,-1,0};

struct pos{
  int x,y,h;
};

int main(){
  
  int n;
  cin >> n;
  vector<pos> v(n);
  REP(i,n){
    int x,y,h;cin >> x >> y >> h;
    v[i] = {x,y,h};
  }
  P res;
  REP(x,101){
    REP(y,101){
      REP(j,n){
        if(v[j].h > 0){
          int h = abs(v[j].x-x)+abs(v[j].y-y)+v[j].h;
          bool is = true;
          for(int i = 1;i < n;i++){
            if(max(h - abs(v[(i+j)%n].x-x) - abs(v[(i+j)%n].y-y),0ll) != v[(i+j)%n].h)is = false;
          }
          if(is){
            cout << x << " " << y << " " << h << endl;
            return 0;
          }
          break;
        }
      }
    }
  }
  


  

  return 0;
}