#include<iostream>
#include<set>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long li;
#define maximize(a,b) (a<(b)?a=(b),1:0)
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
// map 型
template<class S,class T>
std::ostream& operator<<(std::ostream& os, const map<S,T>& mp){
  for(const pair<S,T>& x: mp){
    cout << "[" << x.first << "]=" << x.second << " ";
  }
  return os;
}


int gcd(int a,int b){ return b?gcd(b,a%b):a; }
li lcm(li a,li b){ return a/gcd(a,b)*b; }

// [0,a]
li totient(li a,int c,int d){
  li l=lcm(c,d);
  return a-(a/c+a/d-a/l);
}

int main(){
  int n,k; cin >>n >>k;
  string s; cin >>s;
  vector<int> smry;
  if(s[0]=='0') smry.push_back(0);
  int cnt=1;
  rep(i,n-1){
    if(s[i]==s[i+1]){
      cnt++;
    }else{
      smry.push_back(cnt);
      cnt=1;
    }
  }
  smry.push_back(cnt);
  if(s[n-1]=='0') smry.push_back(0);
  int m=smry.size();
  if(df)print(m,k);
  if(k*2+1>=m){
    print(n);
    return 0;
  }
  if(df)print(smry);
  int sum=0;
  rep(i,2*k+1) sum+=smry[i];
  if(df)print("sum:",0,2*k,":",sum);
  int ma=sum,lim=m/2-k;
  rep(i,lim){
    sum-=smry[i*2]+smry[i*2+1];
    int c=smry[(i+k)*2+1],d=smry[(i+k+1)*2];
    sum+=c+d;
    if(df) print("-",smry[i*2],smry[i*2+1],"+",c,d,"->",sum);
    ma=max(ma,sum);
  }
  print(ma);
}



