#include<iostream>
#include<vector>
using namespace std;
typedef long long li;
#define repa(i,a,n) for(int i=(a);i<(n);i++)
#define rep(i,n) for(int i=0;i<(n);i++)
#define df 0
template<class T> void print(const T& t){ cout << t << "\n"; }
template<class T, class... Ts> void print(const T& t, const Ts&... ts) { cout << t; if (sizeof...(ts)) cout << " "; print(ts...); }

int main(){
  int n; cin >>n;
  vector<int> c(n-1),s(n-1),f(n-1);
  rep(i,n-1){
    cin >>c[i] >>s[i] >>f[i];
  }
  rep(j,n){
    int t=0;
    repa(i,j,n-1){
      //      if(df)print(s[i],f[i]);
      if(t<s[i])t=s[i];
      if(t%f[i])t=(t/f[i]+1)*f[i];
      t+=c[i];
    }
    print(t);
  }
}
