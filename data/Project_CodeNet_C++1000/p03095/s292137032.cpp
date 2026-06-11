#include<iostream>
#include<map>
using namespace std;
typedef long long li;
#define MOD 1000000007
#define rep(i,n) for(int i=0;i<(n);i++)
#define df 0
template<class T> void print(const T& t){ cout << t << "\n"; }
template<class T, class... Ts> void print(const T& t, const Ts&... ts) { cout << t; if (sizeof...(ts)) cout << " "; print(ts...); }

int main(){
  map<char,int> mp;
  int n; cin >>n;
  string s; cin >>s;
  rep(i,n){
    mp[s[i]]++;
  }
  li ans=1;
  for(pair<char,int> x:mp){
    (ans*=x.second+1)%=MOD;
  }
  print(ans-1);
}
