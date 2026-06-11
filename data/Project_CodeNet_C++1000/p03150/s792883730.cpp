#include<iostream>
#include<numeric>
#include<set>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
typedef long long li;
#define chmin(a,b) (a>(b)?a=(b),1:0)
#define abs(n) max((n),-(n))
#define dist(a,b) max((a)-(b),(b)-(a))
#define chmax(a,b) (a<(b)?a=(b),1:0)
#define repa(i,a,n) for(int i=(a);i<(n);i++)
#define MOD 1000000000
#define rep(i,n) for(int i=0;i<(n);i++)

#define df 0
template<class T> void print(const T& t){ cout << t << "\n"; }
template<class T, class... Ts> void print(const T& t, const Ts&... ts) { cout << t; if (sizeof...(ts)) cout << " "; print(ts...); }
// Container コンテナ型, map以外
template< template<class ...> class Ctn,class T>
std::ostream& operator<<(std::ostream& os,const Ctn<T>& v){
  // ここでストリームに obj を書き込みます。
  auto itr=v.begin();
  while(itr!=v.end()){
    if(itr!=v.begin())cout << " ";
    cout << *(itr++);
  }
  return os;
}
// map 型
template<class S,class T>
std::ostream& operator<<(std::ostream& os, const map<S,T>& mp){
  // ここでストリームに obj を書き込みます。
  for(const pair<S,T>& x: mp){
    cout << "[" << x.first << "]=" << x.second << "\n";
  }
  return os;
}


int operator<(vector<int> v1,vector<int> v2){
  rep(i,v1.size())
    if(v1[i]>v2[i]) return 0;
  return 1;
}


string key="keyence";

int main(){
  string s; cin >>s;
  int f=-1;
  rep(i,7){
    if(s[i]!=key[i]){
      f=i;break;
    }
  }
  if(f==-1){
    print("YES");
    return 0;
  }
  int n=s.size();
  //  print(f);
  repa(i,f,7){
    if(s[n-7+i]!=key[i]){
      //      print(s[n-7+i],key[i]);
      f=-1;break;
    }
  }
  if(f==-1){
    print("NO");
    return 0;
  }
  print("YES");
}



