#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long li;
#define rep(i,n) for(int i=0;i<(n);i++)
#define df 0
template<class T> void print(const T& t){ cout << t << "\n"; }
template<class T, class... Ts> void print(const T& t, const Ts&... ts) { cout << t; if (sizeof...(ts)) cout << " "; print(ts...); }
template< template<class ...> class Ctn,class T>
std::ostream& operator<<(std::ostream& os,const Ctn<T>& v){
  auto itr=v.begin();
  while(itr!=v.end()){
    if(itr!=v.begin())cout << " ";
    cout << *(itr++);
  }
  return os;
}


int main(){
  int n,m; cin >>n >>m;
  vector<li> d(m-1),v(m);
  rep(i,m){
    cin >>v[i];
  }
  if(n>=m){
    print(0);
    return 0;
  }
  sort(v.begin(),v.end());
  rep(i,m-1) d[i]=v[i+1]-v[i];
  sort(d.begin(),d.end(),greater<li>());
  li s=0; rep(i,n-1) s+=d[i];
  print(v[m-1]-v[0]-s);
}
