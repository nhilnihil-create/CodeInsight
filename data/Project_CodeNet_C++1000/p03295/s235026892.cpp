#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007

struct ran{
  int l,r;
  bool operator<(const ran &other)const{return r < other.r;}
};

int main(){

  int n,m;
  cin >> n >> m;
  vector<ran> v(m);
  rep(i,m)cin >> v[i].l >> v[i].r;
  sort(ALL(v));
  int last = -1;
  int res = 0;
  rep(i,m)if(v[i].l > last)last = v[i].r-1,res++;
  cout << res << endl;
  



  return 0;
}