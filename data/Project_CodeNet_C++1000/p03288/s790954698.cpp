#include<iostream>
#include<vector>
using namespace std;
typedef long long li;
#define repa(i,a,n) for(int i=(a);i<(n);i++)
#define yn(i) print((i)?"Yes":"No")
#define rep(i,n) for(int i=0;i<(n);i++)

#define df 0
template<class T> void print(const T& t){ cout << t << "\n"; }
template<class T, class... Ts> void print(const T& t, const Ts&... ts) { cout << t; if (sizeof...(ts)) cout << " "; print(ts...); }
// pair 型
template<class S,class T>
std::ostream& operator<<(std::ostream& os, const pair<T,S>& p){
  cout << "(" << p.first << "," << p.second << ")";
  return os;
}

// Container コンテナ型, map以外
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
  int r; cin >>r;
  int abc=1200,arc=2800;
  if(r<abc){
    print("ABC");
  }else if(r<arc){
    print("ARC");
  }else{
    print("AGC");
  }
  
}



