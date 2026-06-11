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
#define INF (1 << 29)
#define MOD 1000000007
//int dx[4] = {1,0,0,-1};
//int dy[4] = {0,1,-1,0};


int main(){

  string s;
  int k;
  set<string> se;
  cin >> s >> k;
  for(int i = 0;i < s.size();i++){
    for(int j = i;j < i+5;j++){
      se.insert(s.substr(i,j - i + 1));
    }
  }
  auto itr = se.begin();
  for(int i = 0;i < k-1;i++)itr++;
  cout << *itr  << endl;
  return 0;
}