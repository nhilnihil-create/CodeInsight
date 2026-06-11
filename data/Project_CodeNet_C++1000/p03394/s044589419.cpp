#include<iostream>
#include<vector>
using namespace std;
typedef long long li;
#define rep(i,n) for(int i=0;i<(n);i++)
#define df 0
template<class T> void print(const T& t){ cout << t << "\n"; }
template<class T, class... Ts> void print(const T& t, const Ts&... ts) { cout << t; if (sizeof...(ts)) cout << " "; print(ts...); }
// vector 型
template<class T>
std::ostream& operator<<(std::ostream& os, const vector<T>& v){
  // ここでストリームに obj を書き込みます。
  for(const T& t:v) cout << t << " ";
  return os;
}

li gcd(li a,li b){
  return (b==0)?a:gcd(b,a%b);
}

void next(int& a){
  do{
    a++;
  }while(gcd(6,a)==1);
}


int main(){
  int n; cin >>n;
  int a=1;li s=0;
  vector<int> v;
  if(n==3){
    print(2,3,25);
    return 0;
  }
  rep(i,n-2){
    next(a);
    s+=a;
    v.push_back(a);
  }
  next(a);
  while(gcd(6,s+a)==1) next(a);
  v.push_back(a);
  s+=a;
  next(a);
  while((s+a)%6) next(a);
  v.push_back(a);
  print(v);
}
