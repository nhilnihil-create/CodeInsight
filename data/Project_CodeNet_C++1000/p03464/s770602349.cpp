#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long li;
#define ceil(n,a) ((((n)+(a)-1)/(a))*(a))
#define rep(i,n) for(int i=0;i<(n);i++)
#define df 0
template<class T> void print(const T& t){ cout << t << "\n"; }
template<class T, class... Ts> void print(const T& t, const Ts&... ts) { cout << t; if (sizeof...(ts)) cout << " "; print(ts...); }

int main(){
  int n; cin >>n;
  vector<li> a(n);
  rep(i,n) cin >> a[i];
  reverse(a.begin(),a.end());
  li mi=2,ma=3;
  rep(i,n){
    mi=ceil(mi,a[i]);
    ma=ceil(ma,a[i]);
  }
  if(mi==ma)print(-1);
  else print(mi,ma-1);
}
