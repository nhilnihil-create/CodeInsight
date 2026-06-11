#include<iostream>
using namespace std;
typedef long long li;
#define yn(i) print((i)?"YES":"NO")
#define rep(i,n) for(int i=0;i<(n);i++)
#define df 0
template<class T> void print(const T& t){ cout << t << "\n"; }
template<class T, class... Ts> void print(const T& t, const Ts&... ts) { cout << t; if (sizeof...(ts)) cout << " "; print(ts...); }

int main(){
  string s; cin >>s;
  string t="AKIHABARA";
  int n=s.size();
  if(n>9){
    yn(0);
    return 0;
  }
  int j=0;
  rep(i,n){
    if(df)print(s[i],t[j]);
    while(t[j]!=s[i]){
      if(t[j]!='A'){
        yn(0);
        return 0;
      }
      j++;
      if(j>=9){
        yn(0);
        return 0;
      }
      if(df)print(s[i],t[j]);
    }
    j++;
  }
  if(j==t.size()){
    yn(1); return 0;
  }
  if(t[j]=='A'){
    j++;
  }
  yn(j==t.size());
}
