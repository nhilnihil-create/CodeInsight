#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long li;
#define rep(i,n) for(int i=0;i<(n);i++)
#define df 0
template<class T> void print(const T& t){ cout << t << "\n"; }
template<class T, class... Ts> void print(const T& t, const Ts&... ts) { cout << t; if (sizeof...(ts)) cout << " "; print(ts...); }

int sign(int j,int t){
  return (j&(1<<t))?1:-1;
}

int main(){
  int n,m; cin >>n >>m;
  vector<li> v[8];
  rep(i,n){
    li a,b,c; cin >>a >>b >>c; 
    rep(j,8){
      v[j].push_back(sign(j,0)*a+sign(j,1)*b+sign(j,2)*c);
    }
  }
  
  li ans=0;
  rep(j,8){
    li tmp=0;
    sort(v[j].begin(),v[j].end());
    rep(i,m){
      tmp-=v[j][i];
    }
    ans=max(ans,tmp);
  }
  print(ans);
}
