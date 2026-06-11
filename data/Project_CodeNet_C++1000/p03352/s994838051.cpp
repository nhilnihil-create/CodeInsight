#include<iostream>
using namespace std;
typedef long long li;
#define repa(i,a,n) for(int i=(a);i<(n);i++)
#define rep(i,n) for(int i=0;i<(n);i++)
#define df 0
template<class T> void print(const T& t){ cout << t << "\n"; }
template<class T, class... Ts> void print(const T& t, const Ts&... ts) { cout << t; if (sizeof...(ts)) cout << " "; print(ts...); }

int main(){
  int x; cin >>x;
  int m=1;
  repa(i,2,x){
    int b=i*i;
    while(b<=x){
      m=max(m,b);
      b*=i;
    }
  }
  print(m);
}
