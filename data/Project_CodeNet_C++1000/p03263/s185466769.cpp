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
#define INF (1 << 30)
#define MOD 1000000007
//int dy[4] = {-1,0,0,1};
//int dx[4] = {0,1,-1,0};


int main(){

  int h,w;
  cin >> h >> w;
  vector<vector<int>> v(h,vector<int>(w));
  REP(i,h)REP(j,w)cin >> v[i][j];
  bool is = false;
  int count = 0;
  vector<tuple<int,int,int,int>> tu;
  REP(i,h){
    if(!(i & 1)){
      REP(j,w){
        if(is)get<2>(tu[tu.size()-1]) = i+1,get<3>(tu[tu.size()-1]) = j+1,is = false,v[i][j]++,count++;
        if(v[i][j] & 1){
          tu.push_back(make_tuple(i+1,j+1,0,0));
          is = true;
        }
      }
    }else{
      REPD(j,w){
        if(is)get<2>(tu[tu.size()-1]) = i+1,get<3>(tu[tu.size()-1]) = j+1,is = false,v[i][j]++,count++;
        if(v[i][j] & 1){
          tu.push_back(make_tuple(i+1,j+1,0,0));
          is = true;
        }
      }
    }
  }

  cout << count << endl;
  REP(i,count)cout << get<0>(tu[i]) << " " << get<1>(tu[i]) << " " << get<2>(tu[i]) << " " << get<3>(tu[i]) << endl;




  

  return 0;
}
