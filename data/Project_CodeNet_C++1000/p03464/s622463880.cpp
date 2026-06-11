#include<iostream>
#include<vector>
using namespace std;
typedef long long li;
//#define ceil(a,b) (((a)+(b)-1)/(b))
li ceil(li a,li b){
  return a/b+(a%b?1:0);
}
#define rep(i,n) for(int i=0;i<(n);i++)
#define df 0
template<class T> void print(const T& t){ cout << t << "\n"; }
template<class T, class... Ts> void print(const T& t, const Ts&... ts) { cout << t; if (sizeof...(ts)) cout << " "; print(ts...); }

int main(){
  li n; cin >>n;
  vector<li> a(n);rep(i,n) cin >>a[i];
  if(a[n-1]!=2){
    print(-1);
    return 0;
  }
  li mi=2,ma=4;
  rep(_i,n){
    int i=n-1-_i;
    mi=ceil(mi,a[i])*a[i];
    ma=ceil(ma,a[i])*a[i];
  }
  if(mi==ma) print(-1);
  else print(mi,ma-1);
}
